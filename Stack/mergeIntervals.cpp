
void mergeIntervals(vector<vector<int>> intervals)
{
	stack<vector<int>> st;

	int first = intervals[0][0];
	int second = intervals[0][1];

	st.push({first,second});

	for(int i=1; i<intervals.size();i++)
	{
		vector<int> temp=st.top();
		first=temp[0];
		second=temp[1];

		if(second>=intervals[i][0])
		{
			first=min(first,intervals[i][0]);
			second=max(second,intervals[i][1]);
			st.pop();
			st.push({first,second});
		}
		else
		{
			first=intervals[i][0];
			second=intervals[i][1];

			st.push({first,second});
		}
	}

	//stack will contain merge intervals
}