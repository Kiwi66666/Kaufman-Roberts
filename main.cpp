#include <iostream>

using namespace std;
void iksy(float x[], float a[], int t[], int n, int m) {
    float help;
    for (int i = 2; i<=m; i++) {
        help = 0;
        for (int j = 0; j<n; j++) {
        	if(i-j-2<0) {
        		help+=t[j]*a[j];
        		break;
			}
        	help+=t[j]*a[j]*x[i-j-1];
		}
        x[i] = help/i;
    }
}

int main()
{
    int n;
    cout << "Podaj liczbe klas zgloszen \n";
    cin >> n;
    float a[n], b[n];
    int t[n];
    cout << "Podaj ruchy \n";
    for (int i = 1; i<=n; i++) {
        cout << i << " klasy zgloszen\n";
        cin >> a[i-1];
    }
    cout << "Podaj ilosc potrzebnych kanalow dla \n";
    for (int i = 1; i<=n; i++) {
        cout << i << " klasy zgloszen\n";
        cin >> t[i-1];
    }
    cout << "Podaj liczbe kanalow\n";
    int m;
    cin >> m;
    for (int i = 0; i<n; i++) {
    	if (t[i]>m) {
    		cout << "zle dane";
    		return 0;
		}
	}
    float x[m+1], p[m+1];
    x[0] = 1;
    x[1] = a[0];
    iksy(x, a, t, n, m); //wyliczenie wszystkich x
    /*for (int i = 0; i<=m; i++) { //pêtla testowa, pokazuje x
        cout <<"x" << i << ". " << x[i] << "\n";
    }*/
    float suma = 0; //suma wszystkich x
    for (int i = 0; i<=m; i++) {
    	suma+=x[i];
	}
	cout << "Prawdopodobienstwa stanu zajetosci kanalow: \n";
	for (int i = 0; i<=m; i++) { //wyliczenie wszystkich p i wyœwietlenie
		p[i] = x[i]/suma;
		cout << "P(" << i << ") = " << p[i] << "\n";
	}
	cout << "Prawdopodobienstwa blokady strumienia zgloszen klasy: \n";
	for (int i = 0; i < n; i++) { //wyliczenie i wyœwietlenie wszystkich b
		suma = 0;
		for (int j = m - t[i]+1; j <= m; j++) {
			suma+=p[j];
		}
		b[i] = suma;
		cout << "b(" << i+1 << ") = " << b[i] << "\n";
	}
    return 0;
}

