template <class T>
inline void scan_d(T &ret) {
	char c; ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}

inline void out(int x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}
