#include <stdio.h>
#include <string.h>

/* strcpy: copy t to s; array subscript version */
void strcpy_array_version(char* s, char* t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* strcpy: copy t to s; pointer version 1 */
void strcpy_pointer_version1(char* s, char* t)
{
    int i;
    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy_pointer_version2(char* s, char* t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

/* strcpy: copy t to s; pointer version 3 (final) */
void strcpy_pointer_version3(char* s, char* t)
{
    while (*s++ = *t++)
        ;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t; array version */
int strcmp_array_version(char* s, char* t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t; pointer version */
int strcmp_pointer_version(char* s, char* t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* Function to print a string with character-by-character analysis */
void print_string_analysis(char* str, char* name)
{
    printf("%s: \"%s\"\n", name, str);
    printf("  Address: %p\n", (void*)str);
    printf("  Length: %zu\n", strlen(str));
    printf("  Characters: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("'%c'(0x%02x) ", str[i], (unsigned char)str[i]);
    }
    printf("'\\0'(0x00)\n\n");
}

int main()
{
    printf("=== Chapter 5.5: Character Pointers and Functions ===\n\n");

    /* Example 1: String constants and character pointers */
    printf("1. String Constants and Character Pointers:\n");
    char* pmessage;
    pmessage = "now is the time";
    printf("   Pointer assignment: pmessage = \"%s\"\n", pmessage);
    printf("   printf with string constant: ");
    printf("hello, world\n\n");

    /* Example 2: Array vs Pointer declaration */
    printf("2. Array vs Pointer Declaration:\n");
    char amessage[] = "now is the time"; /* an array */
    char* pmessage2 = "now is the time"; /* a pointer */

    print_string_analysis(amessage, "   amessage[]");
    print_string_analysis(pmessage2, "   *pmessage2");

    /* Example 3: Modifying array vs pointer */
    printf("3. Modifying Array vs Pointer:\n");
    amessage[0] = 'N'; /* Valid: can modify array contents */
    printf("   Modified amessage: \"%s\"\n", amessage);

    /* Note: We can't modify string constant that pmessage2 points to */
    pmessage2 = "new string"; /* Valid: pointer can point elsewhere */
    printf("   Reassigned pmessage2: \"%s\"\n\n", pmessage2);

    /* Example 4: Testing strcpy functions */
    printf("4. Testing strcpy Functions:\n");
    char dest1[50], dest2[50], dest3[50], dest4[50];
    char* source = "Hello, C Programming!";

    strcpy_array_version(dest1, source);
    printf("   strcpy_array_version: \"%s\"\n", dest1);

    strcpy_pointer_version1(dest2, source);
    printf("   strcpy_pointer_version1: \"%s\"\n", dest2);

    strcpy_pointer_version2(dest3, source);
    printf("   strcpy_pointer_version2: \"%s\"\n", dest3);

    strcpy_pointer_version3(dest4, source);
    printf("   strcpy_pointer_version3: \"%s\"\n", dest4);
    printf("\n");

    /* Example 5: Testing strcmp functions */
    printf("5. Testing strcmp Functions:\n");
    char* str1 = "apple";
    char* str2 = "banana";
    char* str3 = "apple";

    printf("   Comparing \"%s\" and \"%s\":\n", str1, str2);
    printf("     strcmp_array_version: %d\n", strcmp_array_version(str1, str2));
    printf("     strcmp_pointer_version: %d\n", strcmp_pointer_version(str1, str2));

    printf("   Comparing \"%s\" and \"%s\":\n", str1, str3);
    printf("     strcmp_array_version: %d\n", strcmp_array_version(str1, str3));
    printf("     strcmp_pointer_version: %d\n", strcmp_pointer_version(str1, str3));

    printf("   Comparing \"%s\" and \"%s\":\n", str2, str1);
    printf("     strcmp_array_version: %d\n", strcmp_array_version(str2, str1));
    printf("     strcmp_pointer_version: %d\n", strcmp_pointer_version(str2, str1));
    printf("\n");

    /* Example 6: Multiple string constants */
    printf("6. Multiple String Constants:\n");
    char* messages[] = {
        "First message",
        "Second message",
        "Third message",
        "Last message"
    };
    for (int i = 0; i < 4; i++) {
        printf("   messages[%d]: \"%s\" (at %p)\n", i, messages[i], (void*)messages[i]);
    }
    printf("\n");

    /* Example 7: String manipulation with pointers */
    printf("7. String Manipulation with Pointers:\n");
    char text[] = "Pointers are powerful";
    char* ptr = text;
    printf("   Original: \"%s\"\n", text);
    printf("   Character by character: ");
    while (*ptr) {
        printf("%c", *ptr++);
    }
    printf("\n\n");

    /* Example 8: Finding string length manually */
    printf("8. Manual String Length Calculation:\n");
    char* test_str = "Calculate my length";
    int length = 0;
    char* temp = test_str;
    while (*temp++) {
        length++;
    }
    printf("   String: \"%s\"\n", test_str);
    printf("   Manual length: %d\n", length);
    printf("   strlen() result: %zu\n\n", strlen(test_str));

    /* Example 9: String concatenation simulation */
    printf("9. String Concatenation:\n");
    char first[20] = "Hello, ";
    char* second = "World!";
    int i = 0;
    while (first[i] != '\0') {
        i++;
    }
    int j = 0;
    while (second[j] != '\0') {
        first[i++] = second[j++];
    }
    first[i] = '\0';
    printf("   Result: \"%s\"\n\n", first);

    /* Example 10: Standard library vs custom functions */
    printf("10. Standard Library vs Custom Functions:\n");
    char lib_dest[50], custom_dest[50];
    char* src = "Testing comparison";

    /* Using standard library */
    strcpy(lib_dest, src);
    printf("    Standard strcpy: \"%s\"\n", lib_dest);

    /* Using our custom function */
    strcpy_pointer_version3(custom_dest, src);
    printf("    Custom strcpy: \"%s\"\n", custom_dest);

    printf("    strcmp results: %d (standard) vs %d (custom)\n",
        strcmp(lib_dest, custom_dest),
        strcmp_pointer_version(lib_dest, custom_dest));

    return 0;
}