# sizeof operator
- Queries size of the object or type.
  - Used when actual size of the object must be known.
- 객체 또는 유형의 크기를 쿼리합니다.
  - 객체의 실제 크기를 알아야 할 때 사용됩니다.
- https://en.cppreference.com/w/c/language/sizeof.html

# Result

```bash
sizeof(float)          = 4
sizeof(void(*)(void))  = 8
sizeof(char[10])       = 10
sizeof 'a'             = 4
sizeof &main           = 8
sizeof "hello"         = 6
sizeof x               = 2
sizeof (x+1)           = 4
```
