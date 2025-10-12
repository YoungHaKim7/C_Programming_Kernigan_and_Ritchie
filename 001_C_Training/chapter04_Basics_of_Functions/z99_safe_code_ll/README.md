# Output (typical 32-bit system)

```bash
int  version: 147483648
long version: 86400000
```

# Related suffixes
- Suffix	Meaning	Example
||||
|-|-|-|
|L or l |	long |	1234L|
|UL or ul	| unsigned long |	1234UL|
|LL |	long long	|1234LL|
|ULL |	unsigned long long| 	1234ULL|


# Result(64bit아키텍처 컴퓨터에서는 문제점을 모르지만 32bit computer에서 에러...ㅠㅠ)

```
./target/z99_safe_code_ll

int  version: 86400000
long version: 86400000
  
```
