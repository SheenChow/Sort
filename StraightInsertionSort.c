//数据类型见文件：DataRecordType.c
直接插入排序（Stragiht Insertion Sort）
//前提是设置一个长度为n+1的数组
void SInsertSort(SqList &L) //L是一个线性表,下标0处设置哨兵
{
	for (int i = 2; i <= L.length; ++i)
	{
		if(LT(L.r[i].key, L.r[i-1].key)) //注意，比较的是关键字，因为是按照关键字有序
		{
			L.r[0] = L.r[i]; //设置监视哨
			L.r[i] = L.r[i-1];
			for (int j = i-2; LT(L.r[0].key, L.r[j].key); ++j) //因为已经同i-1比较过了，所以从i-2开始从右往左进行比较
			{
				L.r[j+1] = L.r[j];
			}
			//循环到最后的时候，j已经为0
			L.r[j+1] = L.r[0];
		}
	}
}