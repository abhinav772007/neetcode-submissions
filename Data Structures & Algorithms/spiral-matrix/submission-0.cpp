class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        int n=matrix.size(),m=matrix[0].size();
        int ct=0,br=0,er=n-1,bc=0,ec=m-1;
        while(bc<=ec && br<=er){
            for(int i=bc;i<=ec;i++){
                out.push_back(matrix[br][i]);
                ct++;}
            br++;

            for(int i=br;i<=er;i++){
                out.push_back(matrix[i][ec]);
                ct++;}
            ec--;
           if(er>=br){for(int i=ec;i>=bc;i--){out.push_back(matrix[er][i]);ct++;}
            er--;}
            if(ec>=bc){for(int i=er;i>=br;i--){out.push_back(matrix[i][bc]);ct++;}
            bc++;}
        }
        return out;
    }
};
