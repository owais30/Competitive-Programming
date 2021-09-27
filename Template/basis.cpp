
/* d for dimension of vector
 * cbasis stores final basis
 * sz stores the current size of basis
 * 1163 E
*/

const int d = 21; 
int basis[d]; 
// f be the first position in the vector, where bit is set
// basis[i] keeps the mask of the vector whose f value is i
vector<int> cbasis;
// cbasis stores original basis without modifications
// basis can be used to greedy make a number smaller

int sz; // current basis size

void insertVector(int mask){
	int tmp = mask;
	for(int i=0; i<d; ++i){
		if((mask >> i & 1) == 0) continue;
		if(!basis[i]){
			basis[i] = mask;
			++sz;
			cbasis.push_back(tmp);
			return;
		}
		mask ^= basis[i];
	}
}

// another approch
// https://codeforces.com/blog/entry/87234

vector<int> basis;

void insertVector(int mask){
    int cmask = mask;
    for(int element: basis){
        cmask = min(cmask, cmask ^ element);
    }
    if(cmask > 0) basis.push_back(cmask);
}

// for min sum
sort(basis.begin(), basis.end());
reverse(basis.begin(), basis.end());
for(int i=0; i<(int)basis.size(); i++){
    for(int j=i+1; j<(int)basis.size(); j++){
        basis[i] = min(basis[i], basis[i] ^ basis[j]);
    }
}

