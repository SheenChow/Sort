/**
 * 堆排序
 */

typedef SqList HeadType;
//调整成“堆”
void HeapAdjust(HeapType &H, int s, int m)
{
	rc = H.r[s];//暂存根节点的值
	for (int j = 2 * s; j <= m; j ++) {
		if (j < m && LT(H.r[j].key, H.r[j + 1].key)) {
			j ++;//找出key值较大的孩子节点
		}
		if (!LT(rc.key, H.r[j].key)) {
			break;//发现rc比较大的根节点大,说明这颗子树已经有序了,应该退出循环
		}
		H.r[s] = H.r[j];
		s = j; //s用于记录rc(即根结点)应该在的位置
	}
	//把rc放在应该在的位置
	H.r[s] = rc;
}//HeapAdjust

//堆排序
void HeapSort(Heap &H) 
{
	//1.建成大顶堆
	for (int i = H.length / 2; i > 0; i --) { //1....H.length / 2处有孩子结点
		HeapAdjust(H, i, H.length);
	}
	//2.调整堆
	for (int j = H.length; j > 0; j --) {
		//这一步相当于取出“堆顶元素”,当取出堆顶元素后,这个元素就不能算作堆的一部分了(不符合堆定义),所以调整堆的时候
		//范围是[1,j-1]
		H.r[1]<-->H.r[j];
		HeapAdjust(H, 1, j - 1);
	}
}//HeapSort

/**
 * 昨天提到了“堆”和“堆排序”的区别,当时并没有意识到什么,后来与郭小凯的争论过程中逐渐意识到,
 * 只有刚开始建成的“堆”符合“堆”的定义,后来在排序过程中应该把有序的元素除去的部分才能叫做“堆”
 * “堆”:根结点大于(或小于)左右孩子结点  PS:并没有规定左右孩子结点的大小
 */



