#include <iostream>
using namespace std;

int main() {
	int t,n,c;
	cin >> t;
	while(t--)
	{
	    cin >> c;
	    int coin[c];
	    for(int i=0;i<c;i++)
            cin >> coin[i];
        cin >> n;
        int memory[n+1];
        for(int i=0;i<=n;i++)
            memory[i] = 0;
        memory[0] = 1;

        for(int j=0;j<c;j++) {
            for(int i=coin[j];i<=n;i++) {
                memory[i] += memory[i-coin[j]];
            }
        }
	    cout << memory[n] << endl;
	}
	return 0;
}
