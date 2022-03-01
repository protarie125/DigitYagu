#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;

vector<int> initializeGame();

int main() {
	const auto& answer = initializeGame();

	auto count = int{ 1 };
	auto isAnswer = false;
	while (!isAnswer) {
		cout << "���� #" << count << " :::: ";

		string guess;
		cin >> guess;

		auto strike = int{ 0 };
		for (int i = 0; i < 4; ++i) {
			if (answer[i] == guess[i] - '0') {
				strike += 1;
			}
		}

		if (4 == strike) {
			cout << "�����մϴ�! ������ ";
			for (const auto& d : answer) {
				cout << d;
			}
			cout << "�̾����ϴ�!\n";

			isAnswer = true;
			break;
		}

		auto ball = int{ 0 };
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (j == i) {
					continue;
				}

				if (answer[j] == guess[i] - '0') {
					ball += 1;
				}
			}
		}

		if (0 == strike && 0 == ball) {
			cout << "�ƿ�!\n";
		}
		else {
			cout << strike << " S / " << ball << " B\n";
		}

		count += 1;
		cout << endl;
	}

	return 0;
}

vector<int> initializeGame()
{
	cout << "������ ���� ��...\n";

	random_device rd{};
	mt19937_64 rng{ rd() };
	uniform_int_distribution<int> dist{ 0, 9 };

	vector<bool> isUsed(10, false);
	vector<int> answer(4, -1);
	for (int i = 0; i < 4; ++i) {
		auto digit = dist(rng);
		while (isUsed[digit]) {
			digit = dist(rng);
		}

		isUsed[digit] = true;
		answer[i] = digit;
	}

	cout << "�Ϸ�!\n";

	return answer;
}