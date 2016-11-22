/**
 * 简单选择排序
 * 注意不同的循环下标界限的区别
 */
void SelectSort(SqList &L)
{
	for (i = 1; i < L.length; i ++) {
		j = SelectMinKey(L, i); //在线性表L中，从i到L.length中查找最小元素的下标
		if (i != j) {
			L.r[i]<->L.r[j];//交换值
		}
	}
}

int SelectMinKey(SqList L, i)
{
	int k = i;
	for (int j = i + 1; j <= L.length; j ++) {
		if (L.r[j] < L.r[i]) {
			k = j;
		}
	}
	return k;
}