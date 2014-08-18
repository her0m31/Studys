int delete(int data)
{
  struct node *x, **p;
  
  p = &root;  /* 根から開始 */
  while( *p != NULL )  /* 削除するデータが見つかるまで */
	{
		if( data == (*p)->data ) /* 削除するデータと一致するか */
          {
			x = *p;
			if( x->left == NULL && x->right == NULL ) /* 子を持っているか */
              {
				*p = NULL; /* 特に問題なく削除可能 */
              }
			else if( x->left == NULL )   /* 右の子だけを持っているか */
              {
				*p = x->right;  /* 削除によって、右の子が現在の位置に移動してくる */
              }
			else if( x->right == NULL )  /* 左の子だけを持っているか */
              *p = x->left;   /* 削除によって、左の子が現在の位置に移動してくる */
            else  /* ２つの子を持っている */{
				*p = delete_min( &x->right );  /* 部分木内の最小のデータを削除する */
				(*p)->right = x->right;
				(*p)->left = x->left;
              }
			free( x );  /* メモリ解放 */
			return 0;   /* 正常に削除成功 */
          }
		if( data < (*p)->data )  /* 現在の節との大小関係を調べる */
          p = &(*p)->left;  /* 追加データの方が小さいので、左部分木へ進む */
		else
          p = &(*p)->right; /* 追加データの方が大きいので、右部分木へ進む */
	}
  
  return 1;  /* 削除するデータが発見できなかった */
}

/*
  最小のデータをもつ節を削除する。
  引数　p:二分探索木（あるいは部分木）へのポインタのポインタ
  戻り値　削除した節のアドレス。
*/

struct node* delete_min(struct node** p)
{
  struct node* x;
  
  /* 最小のデータは、二分探索木の性質上、左の子を辿り続ければ発見できる */
  while( (*p)->left != NULL ) /* 左の子を持たない節まで来たら終了 */
	{
      p = &(*p)->left;  /* 左へ進む */
	}
  
  x = *p;            /* 削除するデータの位置をコピー */
  *p = (*p)->right;  /* 削除対象の右の子を、削除した節の位置に移動させる */
  return x;          /* コピーしておいたアドレスを返す */
}
