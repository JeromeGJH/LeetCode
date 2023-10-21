class Solution {
public:

    string simplifyPath(string path) {
        string ans = "";
        int len = path.length();
        
        if(len == 1){
            return "/";
        }
        vector<string> vs;// = path.split('/');
        vector<string> res;
        
        
        int i = 0;
        string tmp = "";
        for(i = 0; i < len; ++i){
            if(path[i]!='/'){
                tmp.push_back(path[i]);
                if(i == len-1){
                    vs.emplace_back(tmp);
                }
            }else{
                if(tmp.length() != 0){
                    vs.emplace_back(tmp);
                    tmp = "";
                }
            }
        }
        int size = vs.size();



        for(i = 0; i < size; ++i){
            //cout << vs[i].length() <<endl;
            if(vs[i].length() == 0){
                continue;
            }else{
                if(vs[i] == "."){
                    continue;
                }
                if(vs[i] == ".."){
                    if(!res.empty()){
                        res.pop_back();
                    }
                    continue;
                }
                //cout << "here1" <<endl;
                res.emplace_back(vs[i]);
            }

            // if(path[i] == '/'){
            //     if(path[i-1] == '/'){
            //         continue;
            //     }else{
            //         ans.push_back(path[i]);
            //     }
            // }else{
            //     if(i < len -1 && path[i] == '.' && path[i+1] == '/'){
            //         i += 1:
            //         continue;
            //     }
            //     if(i == len -1 && path[i] == '.')
            // }
        }
        if(res.empty()){
            return "/";
        }


        for(auto e : res){
            ans.append("/").append(e);
        }
        return ans;

    }
};
