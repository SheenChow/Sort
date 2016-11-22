//Quick Sort 来源于剑指Offer

//一趟排序 或者叫做分块算法
int Partition(int data[], int length, int start, int end)
{
	if(data == NULL || length <= 0 || start < 0 || end >= length)
	{
		throw new std::exception("Invalid Parameter");
	}
	//选择一个随机数字作为枢轴,
	int index = RandomInRange(start, end);
	//把枢轴放在数组的末尾
	Swap(&data[index], &data[end]);

	//定义一个新的变量记录枢轴的位置
	int small = start - 1;
	//注意此处的index < end 因为最后一位已经做了枢轴 所以不再跟其作比较
	for(index = start; index < end; index ++)
	{
		if(data[index] < data[end])
		{
			small ++;
			if(index != small)
			{
				Swap(&data[small], &data[index]);
			}
		}
	}

	small ++;
	//把枢轴放在它应该在的位置
	Swap(&data[small], &data[end]);
	//返回枢轴在数组中的下标
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if(start == end) //注意这个判断条件决定了下面的判断条件
	{
		return;
	}

	int index = Partition(data, length, start, end);
	if(index > start)
	{
		QuickSort(data, length, start, index - 1);
	}
	if(index < end)
	{
		QuickSort(data, length, index + 1, end);
	}
}

//或者可以写成如下这样的
void QuickSort(int data[], int length, int start, int end)
{
	if(start >= end) {
		return;
	}
	int index = Partition(data, length, start, end);
	QuickSort(data, length, start, index - 1); //这个时候由于开头的判断条件，如果index = start 就会退出函数
	QuickSort(data, length, index + 1, end);
}