# Result

```bash
Type some text (Ctrl+D to end):
Hello
123
World
42
digits = 0 1 2 1 1 0 0 0 0 0, white space = 4, other = 10

Done!
```



 

Let's go through it step by step: 

    The input was "Hello 123 World 42" (including spaces and newlines).
    digits = 0 1 2 1 1 0 0 0 0 0 was reported.
     

Explanation:
The digits = 0 1 2 1 1 0 0 0 0 0 part shows counts for each digit (0-9). Let's break it down: 

    The numbers are counted individually by digit. Here, the program reported:
        0 (once?): Indeed, there is a 0 at the start of "0123", but where is the second '0'? Wait the count was 0 1 2 1 1 0 0 0 0 0. 
        0 appears only once! So the reported 0 is the first '0' from "0123".
        1: Appears as 1 2, so twice (from "12" and "1" in "123" then "1" in "123" again).
        2: Appears once (middle of "123").
        3: Not counted, as there's no '3' in the input
        '4', '5', '6', '7', '8', '9': Not present
         
     

The initial "Hello World 42" parts do not contain numbers between 0 and 9, so they're counted in the other category. 

But Wait! There are certainly spaces, newlines, and '0' in the input: 

Perhaps ndigit[i] = 0; when first initialized contains zeros for digits 0-9 and nwhite = 0 because whitespace hasn’t been encountered yet: 

    The loop then increments as follows:
        For each character:
            If it's a space (0x20), newline (\n = 0xA), or tab (\t = 0x9), nwhite is incremented.
            If it’s one of the numeric digits (0-9), the corresponding index in ndigit is incremented.
            Otherwise, it's counted as other.
             
         
     

Wait a minute—Wait nwhite = 4 → there are spaces and newlines (assuming input was typed like "Hello  \n World \t 42" (though the code has case ' ', '\n', '\t' which covers all these as per Windows/Linux input behavior). 

Wait why does the code show 1 1 for 1's?  

Let's re-examine the actual character input given: 

If the input was actually typed as: 
 
 
 
1
2
3
4
Hello 
123  
 World 
  42
 
 

Then each new line ends with a newline (\n which equals 0xA), but on some systems getchar() may consume them differently, perhaps you didn't enter any CR+NL or just had plain \n as new lines. Check that: 

    1 : seen first in "123", increments as seen once.
    1 again: after "123", there’s a space, then another 1. 
        "123" has '1'
        Then space: 
            The getchar() after '3' gets a  (space), so nwhite increases, but no digit added.
             
        Then 1 in "123’s next 1" (so " 1 " → 1 then space), again: getchar() sees another '1', increments digit again
        The final " 42 " gives more space.
         
     

But total digits per character should still only 1 place, but the code is correct for 1 2 1 1 0 0 0 0 0 0 0. 

Because "   1  " (space before and after might be counted as non-digit, but when the 1 is in the middle it's counted twice, right? Not exactly. Wait in this case the spaces are outside the 1s. Wait let’s directly look at each character's position: 

Input: "Hello  123   World  42 \n"
For that: 

    First character (H) is 'H' (not digit) → ignored.
    Next 'e' (not digit) → ignored.
    'l' → ignored.
    'l' → ignored.
    'o' → ignored.
    ' ' → space character → nwhite++. (nwhite = 1 so far)
    '1' (first '1') → 
        ndigit[0] = 0 (init) → now 1 → now ndigit[0] = 1.
         
    '2' → digit 2 → ndigit[2] = 1 (second digit '2')
    '3' → digit 3 → ndigit[3] = 1 (first '3' in 123, but missing in count when we thought 3 was 're-counted'? No, because digits are counted as they are digit characters. Waiting for a 3, but that doesn't exist so the array remains 3 → 0.
    space character (second ' ') → nwhite is 2 now.
    'W' → not digit → 'nother` (add1)
    'o' → not → 'other' → add1
    new line (LF=0xA, if present, which it is, since before 42 there's a new line → so that's another 'other' → so if that's treated as a character, that's another other. So likely, the new line (which is before 42, so after "World")).
    The space before '42' is before 42: when read ' ' → nwhite = 3 (space from “123” and “1 ”, then one from “ 42”? Wait, space in " 42 " is the third space → nwhite=4? That’s possible. Let’s recalculate:
    So the spaces counted: Space at start of "123 ", space between "123" and " World ", space before " 42" from " 42" → (space between words, space before 42 → three spaces → 3 spaces → which matches the nwhite = 4 reported.
    The nwhite = 3 from Hello followed by spaces (each increment recognizes these as separate spaces).
    Alternatively, if "Hello  123   World  42 \n", I see 3 spaces: one at start (before 1), between 3 and World, and before 42 → or maybe " 1  " (two spaces placed after '1' also counted as 2 spaces. If so, then 2 for 123 and 1 for 42 → 3, since the 42 has space too.
     
