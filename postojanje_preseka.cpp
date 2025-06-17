#include<bits/stdc++.h> // iz mekog razloga ne radi na test primeru 29. na petlji

using namespace std;

struct point
{
    int x,y; //int je dovoljan, max je 10000
};


int orijentacija(int xa, int ya, int xb, int yb, int xc, int yc) {
  int d = (xb-xa)*(yc-ya) - (xc-xa)*(yb-ya);
  if (d > 0)
    return 1; //pozitivna
  else if (d < 0)
    return -1; //negativna
  else
    return 0; // kolinearne 
}

bool tacka_na_duz(point t1,point t2, point t3){ /// da li je tacka 3 na duzi t1-t2
      if(t3.x < max(t1.x,t2.x) && t3.x >=min(t1.x,t2.x) && t3.y <=max(t1.y,t2.y) && t3.y >=min(t1.y,t2.y)){
        return true;
      }
      else return false;
}

bool presek(point A,point B, point C, point D){

   int  o1 = orijentacija(A.x,A.y,B.x,B.y,C.x,C.y );//a //c//b
    int  o2 = orijentacija(A.x, A.y, B.x,B.y, D.x,D.y);
    int  o3 = orijentacija(C.x,C.y, D.x,D.y, A.x,A.y);
    int  o4 = orijentacija(C.x,C.y, D.x,D.y, B.x,B.y);

    //opsti slucaj
    if (o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0 && o1 != o2 && o3 != o4)
        return true;

    
        
    if (o1 == 0 && tacka_na_duz(A, B, C) || o2 == 0 && tacka_na_duz(A,B,D) || o3 == 0 && tacka_na_duz(C,D,A) || o4 == 0 && tacka_na_duz(C,D,B) ) return true; 
        
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    point A,B,C,D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y; 
    if (presek(A, B, C, D)) {
        cout << "da\n";
    } else {
        cout << "ne\n";
    }
}
