		for (int i = 1; i < P1counter; i++) {					//Move cards up in each deck		
			P1value[i-1] = P1value[i];
			P1suit[i-1] = P1suit[i];
		}
		P1counter--;

		for (int i = 1; i < P2counter; i++) {		
			P2value[i-1] = P2value[i];
			P2suit[i-1] = P2suit[i];
		}
		P2counter--;




				rotate(P1value, P1value+1, P1value+P1counter); 					// rearrange deck
				rotate(P1suit, P1suit+1, P1suit+P1counter);
				P1counter --;

				rotate(P2value,P2value+1,P2value+P2counter);
				rotate(P2suit, P2suit+1, P2suit+P2counter);
				P2counter --;


	for (int i = 0; i < 2; i++){
		cout << "\n*************************" << endl;						//test output!
		for (int i = 0; i < P1counter; i++) {
			cout << P1value[i];
			cout << P1suit[i] << " ";
		}
		cout << "\n*************************" << endl;
		for (int i = 0; i < P2counter; i++) {
			cout << P2value[i];
			cout << P2suit[i] << " ";
		}
		cout << endl;
	}






		cout << "\n*************************" << endl;						//test output!
		for (int i = 0; i < 52*deck; i++) {
			cout << cardValues[i];
			cout << cardSuits[i] << " ";
		}
		cout << endl;
