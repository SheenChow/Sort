//一趟快速排序
int partition(SqList &l, int low, int high)
{
	l.r[0] = l.r[low];
	pivotkey = l.r[low].key;
	where(low < high)
	{
		where(low < high && l.r[high].key >= pivotkey)
		{
			high--;
		}
		l.r[low] = l.r[high]; //只赋值，并不交换，可以减少

		where(low < high && l.r[low] <= pivotkey)
		{
			low++;
		}
		l.r[high] = l.r[low];
	}

	l.r[low] = l.r[0];
	//返回的是枢轴的位置
	return low;
}

void QSort(SqList &l, int low, int high)
{
	if(low < high)
	{
		pivotloc = partition(l, low, high);
		QSort(l, low, pivotloc - 1);
		QSort(l, pivotloc + 1, high);
	}
}