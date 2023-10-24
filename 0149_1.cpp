class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
    }

    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len <= 2){
            return len;
        }
        int i = 0, j  =0, k;
        sort(points.begin(), points.end(), compare);
        vector<int> lines(len, 0);
        double a, b;
        int res = 2;
        int count = 1;
        int v_end = 0;
        double pre_a, pre_b;
        bool second = true;
        int pre_x;
        for(i = 0; i < len-1; ++i){
            count = 1;
            for(j = i + 1; j < len; ++j){
                //cout << i << " "<<j<<endl;
                if(points[i][0] == points[j][0]){
                    count += 1;
                }else{
                    v_end = j;
                    break;
                }
            }
            lines[i] = max(lines[i], count);
            if(j > v_end){
                v_end += j + 1;
                
            }
            //cout << count<<endl;
            //cout << v_end <<endl;
            //cout << points[i][0] << " "<<points[v_end][0]<<endl;
            
            for(j = v_end; j < len; ++j){
                pre_a = ((double)points[i][1] - points[j][1]) / ((double)points[i][0] - points[j][0]);
                pre_b = 0 - pre_a * points[i][0] + (double)points[i][1];
                pre_x = points[j][0];
                count = 2;
                cout <<i << " "<< j << " pre a b " << pre_a << " "<<pre_b<<endl;
                for(k = j+1; k < len; ++k){
                    if(points[k][0] == pre_x){
                        continue;
                    }else{
                        a = ((double)points[k][1] - points[j][1]) / ((double)points[k][0] - points[j][0]);
                        b = 0 - a * points[k][0] + (double)points[k][1];
                        cout <<k <<"            "<< a << " "<<b<<endl;
                        //cout << "pre a b " << pre_a << " "<<pre_b<<endl;
                        if(abs(a - pre_a) <= 1e-6 && abs(b - pre_b) <= 1e-6){
                            cout << "here " << k<<endl;
                            count += 1;
                            cout << count << k<<endl;
                        }
                    }
                }
                lines[i] = max(lines[i], count);
            }
            
            res = max(res, lines[i]);
        }
        return res;

    }
};
