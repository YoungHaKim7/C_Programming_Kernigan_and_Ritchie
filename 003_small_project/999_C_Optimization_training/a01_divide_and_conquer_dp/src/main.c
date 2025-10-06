int m, n;
vector<long long> dp_before, dp_cur;

long long C(int i, int j);

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};

    for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

long long solve() {
    dp_before.assign(n,0);
    dp_cur.assign(n,0);

    for (int i = 0; i < n; i++)
        dp_before[i] = C(0, i);

    for (int i = 1; i < m; i++) {
        compute(0, n - 1, 0, n - 1);
        dp_before = dp_cur;
    }

    return dp_before[n - 1];
}
int main(void)
{

    // Decimal with separators
    // clang-format off
    int dec = 1'000'000; // 1000000

    // Hexadecimal with separators
    // 0xDEADBEEF
    int hex = 0xDEAD'BEEF;

    // Binary (not built-in, but GCC/Clang extensions allow 0b…)
    // 0b10101100
    int bin = 0b1010'1100;

    // Octal with separators
    // same as 0123456
    int oct = 0'123'456;
    // clang-format on

    printf("Decimal: %d\n", dec);
    printf("Hex:     %X\n", hex);
    printf("Binary:  %d (0b1010'1100)\n", bin);
    printf("Octal:   %o\n", oct);

    printf("\n");
    printf("2D array (matrix)\n");

    // 2D array (matrix) with digit separators for readability
    // clang-format off
    int matrix[ROWS][COLS] = {
        { 1,     2,     3,     4 },
        { 10,   20,   30,   40 },
        { 100, 200, 300, 400 }
    };
    // clang-format on

    printf("Matrix (%dx%d):\n", ROWS, COLS);
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        putchar('\n');
    }

    // make matrix init
    int rows = 2, cols = 3;
    int matrix02[rows][cols]; // VLA in C23

    printf("\n");
    printf("Matrix (%dx%d):\n", rows, cols);

    // Fill with i*j
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix02[i][j] = i * j;
        }
    }

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix02[i][j]);
        }
        putchar('\n');
    }

    printf("\n");
    printf("Struct Example \n");

    struct Student s = { .id = 101, .score = 85 };

    printf("Student ID: %d\n", s.id);
    printf("Score: %d\n", s.score);

    // if statement
    if (s.score >= 90) {
        printf("Grade: A\n");
    } else if (s.score >= 80) {
        printf("Grade: B\n");
    } else if (s.score >= 70) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }

    // switch-case (check grade group by tens place)
    switch (s.score / 10) {
    case 10: // 100
    case 9:
        printf("Excellent!\n");
        break;
    case 8:
        printf("Good job!\n");
        break;
    case 7:
        printf("Fair.\n");
        break;
    default:
        printf("Needs improvement.\n");
        break;
    }

    return 0;
}
