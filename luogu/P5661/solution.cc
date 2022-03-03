#include <iostream>
#include <vector>

using namespace std;

int n;
vector< pair<int, int> > subway_ticket;
int sum_price = 0;

int main() {
    cin >> n;
    while(n--) {
	int vehicle, price, minute;
	cin >> vehicle >> price >> minute;
	if(vehicle == 0) {
	    subway_ticket.push_back(make_pair(price, minute));
	    sum_price += price;
	} else {
	    bool got_free = false;
	    for(auto i = subway_ticket.begin(); i != subway_ticket.end(); ) {
		if( minute - (*i).second > 45 ) subway_ticket.erase(i);
		else break;
	    } 
	    if(!subway_ticket.empty()) {
		for(auto i = subway_ticket.begin(); i != subway_ticket.end(); ++i) 
		    if( (*i).first >= price && minute - (*i).second <= 45 ) {
			subway_ticket.erase(i);
			got_free = true;
			break;
		    }
	    }
	    got_free ? 0 : sum_price += price;
	}
    }
    cout << sum_price << endl;
}
