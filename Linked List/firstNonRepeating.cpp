// Question Link : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
// Time Complexity : O(N*26)
// Space Complexity : O(26)

// Question tags : Linked List | Queue
// Linked List  Implementation :
// create double LL of characters. head will always point out first non-repeating character if list is empty then no such character
// create two hash maps first will store address of character address in LL and second hash will store if character has been repeated or not
// if (address==NULL && frequency is false)  then create node add to list
// else if(address==NULL && frequency is true) character has been reapeated print head of list if present
// else if(address != NULL && freqeuency is false) make fraquency true and print head of list

//********************************************************************************************************************


// below is approch using only queue
// implement queue using linked list
string FirstNonRepeating(string A)
{
	queue<char> q;
	int freq[26]={0};
	string ans="";

	for(int i=0;i<A.length();i++)
	{
		char ch = A[i];
		freq[A[i]-'a']++;

		q.push(ch);

		while(!q.empty() && freq[q.front()]>1)
			q.pop();

		if(q.empty())
			ans += '#';
		else
			ans += q.front();

	}

	return ans;
}