void bubbleSort(int* a_pAry, int a_nSize) {
	int temp = 0;
	bool sorted = false; 
	for (int n = a_nSize - 1; n >= 0; n--) {
		if (sorted)
			break;

		sorted = true;
		for (int i = 0; i < n; i++) {
			if (a_pAry[i + 1] >= a_pAry[i])
				continue;

			temp = a_pAry[i];
			a_pAry[i] = a_pAry[i + 1];
			a_pAry[i + 1] = temp;
			sorted = false;
		}
	}
}