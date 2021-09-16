int s1Arr[26] = {0};
    int s2Arr[26] = {0};
    for(int i{}; i < a.length(); i++){
        s1Arr[a[i] - 'a']++;
        s2Arr[b[i] - 'a']++;
    }
    for(int i{}; i < 26; i++){
        if(s1Arr[i] != s2Arr[i]) return false;
    }