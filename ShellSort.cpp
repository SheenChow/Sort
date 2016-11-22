//ShellSort 不稳定的排序 时间复杂度较之于直接插入排序的O(n^2)时间复杂度低 
//主要函数 dlta[t]是增量序列 t是排序的趟数
void ShellSort(SqList *l, int dlta[], int t)
{
	for(int k = 0; k < t; k++)
	{
		ShellInsert(l, dlta[k]);
	}
}

//插入函数
void ShellInsert(SqList *l, int dk)
{
	for(i = dk + 1; i <= l->length; i++)
	{
		if(LT(l->r[i].key, l->r[i - dk].key))
		{
			l->r[0] = l->r[i];
			//寻找插入位置
			for(j = i - dk; j > 0 && LT(l->r[0], l->r[j]); j -= dk)
			{
				l->r[j + dk] = l->r[j];
			}

			l->r[j + dk] = l->r[0];
		}
	}
}