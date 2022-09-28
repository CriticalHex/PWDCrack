#include<ctime>
#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

int main() {
	vector<int> asciiArray;
	vector<int> guess;
	string userIn;
	cout << "Enter a PIN: \n";
	cin >> userIn;
	for (auto c : userIn) {
		asciiArray.push_back(int(c));
		guess.push_back(32);
	}
	auto start = chrono::high_resolution_clock::now();
	while (true) {
		if (guess == asciiArray) {
			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
			cout << "Took: " << duration.count() / double(1000) << " seconds, PWD is: " << userIn;
			break;
		}
		guess[0]++;
		for (int i = 0; i < asciiArray.size(); i++) {
			if (guess[i] % 127 == 0) {
				guess[i + 1]++;
				guess[i] = 32;
			}
		}
	}
	
}