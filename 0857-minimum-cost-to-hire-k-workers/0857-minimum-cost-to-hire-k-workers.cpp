class Solution
{
    public:
        double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
        {
            const int n = quality.size();
            vector<array<double, 2>> worker(n);	// (wage/quality, quality)
            for (int i = 0; i < n; i++)
            {
                worker[i] = { (double) wage[i] / quality[i],
                    (double) quality[i]
                };
            }
           	//partial sort
            partial_sort(worker.rbegin(), worker.rbegin() + (n - k + 1), worker.rend(), greater < > ());

            int quality_sum = 0;

            priority_queue<int> pq;	// max heap for quality
            for (int i = 0; i < k; i++)
            {
            	//Choose the best k workers according to quality/wage
                quality_sum += worker[i][1];
                pq.push(worker[i][1]);
            }
            double pay = quality_sum *worker[k - 1][0];

            for (int i = k; i < n; i++)
            {
                pq.push(worker[i][1]);
                quality_sum += worker[i][1] - pq.top();	//for low cost, higher quality goes away
                pq.pop();

                pay = min(pay, quality_sum *worker[i][0]);
            }
            return pay;
        }
};