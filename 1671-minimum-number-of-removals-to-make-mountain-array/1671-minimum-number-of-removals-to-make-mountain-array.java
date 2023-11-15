class Solution {
	public int minimumMountainRemovals(int[] arr) {
		int n = arr.length;
		// find the LIS from left
		int[] left = new int[n];
		left[0] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j]) {
					if (left[j] > left[i]) {
						left[i] = left[j];
					}
				}
			}
			left[i]++;
		}

		// find the LIS from right
		int[] right = new int[n];
		right[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = n - 1; j > i; j--) {
				if (arr[i] > arr[j]) {
					if (right[j] > right[i]) {
						right[i] = right[j];
					}
				}
			}
			right[i]++;
		}
		// find the longest bitonic subsequence length
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (left[i] != 1 && right[i] != 1)
				max = Math.max(left[i] + right[i] - 1, max);
		}
		return n - max;
	}
}
