int cmp(const void* a, const void* b) {
    return (*(char*)a) - (*(char*)b);
}

// Solution2
bool isAnagram(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen != tLen) return false;
    qsort(s, sLen, sizeof(char), cmp);
    qsort(t, tLen, sizeof(char), cmp);
    
    for (int i = 0; i < sLen; i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
}

// Solution2
// bool isAnagram(char* s, char* t) {
//     int sLen = strlen(s);
//     int tLen = strlen(t);
//     if (sLen != tLen) return false;
//     int* cnt = (int*)calloc(26, sizeof(int));
    
//     for (int i = 0; i < sLen; i++) {
//         cnt[s[i] - 'a']++;
//         cnt[t[i] - 'a']--;
//     }

//     for (int i = 0; i < 26; i++) {
//         if (cnt[i] != 0) return false;
//     }
//     return true;
// }