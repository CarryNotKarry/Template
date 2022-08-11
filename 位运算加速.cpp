// C++ Version
//在某些机器上，效率比 n > 0 ? n : -n 高。
int Abs(int n) {
  return (n ^ (n >> 31)) - (n >> 31);
  /* n>>31 取得 n 的符号，若 n 为正数，n>>31 等于 0，若 n 为负数，n>>31 等于 -1
     若 n 为正数 n^0=n, 数不变，若 n 为负数有 n^(-1)
     需要计算 n 和 -1 的补码，然后进行异或运算，
     结果 n 变号并且为 n 的绝对值减 1，再减去 -1 就是绝对值 */
}

// C++ Version 判断是否是2的非负整数幂
bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }

// C++ Version 对2的非负整数幂取模
int modPowerOfTwo(int x, int mod) { return x & (mod - 1); }

// C++ Version
//在某些机器上，效率比 a > b ? a : b 高。
// 如果 a>=b,(a-b)>>31 为 0，否则为 -1
int max(int a, int b) { return b & ((a - b) >> 31) | a & (~(a - b) >> 31); }
int min(int a, int b) { return a & ((a - b) >> 31) | b & (~(a - b) >> 31); }

//交换两个数
void swap(int &a, int &b) { a ^= b ^= a ^= b; }

// C++ Version
// 获取 a 的第 b 位，最低位编号为 0
int getBit(int a, int b) { return (a >> b) & 1; }

// C++ Version
// 将 a 的第 b 位设置为 1 ，最低位编号为 0
int setBit(int a, int b) { return a | (1 << b); }

// C++ Version
// 将 a 的第 b 位取反 ，最低位编号为 0
int flapBit(int a, int b) { return a ^ (1 << b); }