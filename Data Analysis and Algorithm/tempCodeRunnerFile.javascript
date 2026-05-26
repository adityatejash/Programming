const {
  Document, Packer, Paragraph, TextRun, Table, TableRow, TableCell,
  AlignmentType, HeadingLevel, BorderStyle, WidthType, ShadingType,
  VerticalAlign, PageBreak, Header, Footer, PageNumber, LevelFormat,
  TabStopType, TabStopPosition
} = require('docx');
const fs = require('fs');

// Color palette
const BLUE = "1F4E79";
const LIGHT_BLUE = "2E75B6";
const DARK_GRAY = "2F2F2F";
const LIGHT_GRAY = "F5F5F5";
const CODE_BG = "1E1E1E";
const CODE_TEXT = "D4D4D4";
const HEADER_BG = "2E75B6";
const HEADER_TEXT = "FFFFFF";

const border = { style: BorderStyle.SINGLE, size: 1, color: "CCCCCC" };
const borders = { top: border, bottom: border, left: border, right: border };

function heading1(text) {
  return new Paragraph({
    heading: HeadingLevel.HEADING_1,
    spacing: { before: 360, after: 200 },
    border: { bottom: { style: BorderStyle.SINGLE, size: 8, color: LIGHT_BLUE, space: 6 } },
    children: [new TextRun({ text, bold: true, color: BLUE, size: 32, font: "Arial" })]
  });
}

function heading2(text) {
  return new Paragraph({
    spacing: { before: 280, after: 160 },
    children: [new TextRun({ text, bold: true, color: LIGHT_BLUE, size: 26, font: "Arial" })]
  });
}

function body(text, options = {}) {
  return new Paragraph({
    spacing: { before: 80, after: 80, line: 320, lineRule: "auto" },
    alignment: AlignmentType.JUSTIFIED,
    children: [new TextRun({ text, size: 22, font: "Arial", color: DARK_GRAY, ...options })]
  });
}

function spacer(pt = 120) {
  return new Paragraph({ spacing: { before: pt, after: 0 }, children: [new TextRun("")] });
}

function pageBreak() {
  return new Paragraph({ children: [new PageBreak()] });
}

function sectionLabel(num, title) {
  return new Paragraph({
    spacing: { before: 320, after: 120 },
    children: [
      new TextRun({ text: `Experiment ${num}`, bold: true, color: BLUE, size: 28, font: "Arial" }),
    ]
  });
}

function question(text) {
  return new Paragraph({
    spacing: { before: 160, after: 80 },
    children: [
      new TextRun({ text: "Question: ", bold: true, color: LIGHT_BLUE, size: 22, font: "Arial" }),
      new TextRun({ text, bold: true, color: DARK_GRAY, size: 22, font: "Arial" })
    ]
  });
}

function solutionLabel() {
  return new Paragraph({
    spacing: { before: 120, after: 80 },
    children: [new TextRun({ text: "Solution:", bold: true, underline: {}, size: 22, font: "Arial", color: DARK_GRAY })]
  });
}

function codeBlock(lines) {
  const rows = lines.map(line =>
    new TableRow({
      children: [
        new TableCell({
          borders: { top: { style: BorderStyle.NONE }, bottom: { style: BorderStyle.NONE }, left: { style: BorderStyle.NONE }, right: { style: BorderStyle.NONE } },
          width: { size: 9360, type: WidthType.DXA },
          shading: { fill: "F0F0F0", type: ShadingType.CLEAR },
          margins: { top: 0, bottom: 0, left: 160, right: 160 },
          children: [new Paragraph({
            spacing: { before: 40, after: 40, line: 240, lineRule: "auto" },
            children: [new TextRun({ text: line, font: "Courier New", size: 18, color: "1A1A1A" })]
          })]
        })
      ]
    })
  );

  return new Table({
    width: { size: 9360, type: WidthType.DXA },
    columnWidths: [9360],
    borders: {
      top: { style: BorderStyle.SINGLE, size: 2, color: "AAAAAA" },
      bottom: { style: BorderStyle.SINGLE, size: 2, color: "AAAAAA" },
      left: { style: BorderStyle.SINGLE, size: 2, color: "AAAAAA" },
      right: { style: BorderStyle.SINGLE, size: 2, color: "AAAAAA" },
      insideH: { style: BorderStyle.NONE },
      insideV: { style: BorderStyle.NONE }
    },
    rows
  });
}

function complexityTable(headers, rows) {
  const colWidth = Math.floor(9360 / headers.length);
  const colWidths = headers.map(() => colWidth);

  const headerRow = new TableRow({
    tableHeader: true,
    children: headers.map((h, i) =>
      new TableCell({
        borders,
        width: { size: colWidths[i], type: WidthType.DXA },
        shading: { fill: "2E75B6", type: ShadingType.CLEAR },
        margins: { top: 80, bottom: 80, left: 120, right: 120 },
        verticalAlign: VerticalAlign.CENTER,
        children: [new Paragraph({
          alignment: AlignmentType.CENTER,
          children: [new TextRun({ text: h, bold: true, color: "FFFFFF", size: 20, font: "Arial" })]
        })]
      })
    )
  });

  const dataRows = rows.map((row, ri) =>
    new TableRow({
      children: row.map((cell, ci) =>
        new TableCell({
          borders,
          width: { size: colWidths[ci], type: WidthType.DXA },
          shading: { fill: ri % 2 === 0 ? "EBF3FB" : "FFFFFF", type: ShadingType.CLEAR },
          margins: { top: 60, bottom: 60, left: 120, right: 120 },
          children: [new Paragraph({
            alignment: ci === 0 ? AlignmentType.LEFT : AlignmentType.CENTER,
            children: [new TextRun({ text: cell, size: 18, font: "Courier New", color: DARK_GRAY })]
          })]
        })
      )
    })
  );

  return new Table({
    width: { size: 9360, type: WidthType.DXA },
    columnWidths: colWidths,
    rows: [headerRow, ...dataRows]
  });
}

// ─── CODE BLOCKS PER EXPERIMENT ───────────────────────────────

const exp1Code = [
  "#include <stdio.h>",
  "#include <stdlib.h>",
  "#include <string.h>",
  "",
  "#define MAX 100",
  "",
  "// ── a. Insertion Sort ─────────────────────────────────────",
  "// Time: O(n^2) worst/avg, O(n) best | Space: O(1)",
  "void insertionSort(int arr[], int n) {",
  "    for (int i = 1; i < n; i++) {",
  "        int key = arr[i], j = i - 1;",
  "        while (j >= 0 && arr[j] > key) {",
  "            arr[j + 1] = arr[j];",
  "            j--;",
  "        }",
  "        arr[j + 1] = key;",
  "    }",
  "}",
  "",
  "// ── b. Selection Sort ────────────────────────────────────",
  "// Time: O(n^2) all cases | Space: O(1)",
  "void selectionSort(int arr[], int n) {",
  "    for (int i = 0; i < n - 1; i++) {",
  "        int minIdx = i;",
  "        for (int j = i + 1; j < n; j++)",
  "            if (arr[j] < arr[minIdx]) minIdx = j;",
  "        int tmp = arr[minIdx]; arr[minIdx] = arr[i]; arr[i] = tmp;",
  "    }",
  "}",
  "",
  "// ── c. Bubble Sort ──────────────────────────────────────",
  "// Time: O(n^2) worst/avg, O(n) best | Space: O(1)",
  "void bubbleSort(int arr[], int n) {",
  "    for (int i = 0; i < n - 1; i++) {",
  "        int swapped = 0;",
  "        for (int j = 0; j < n - i - 1; j++) {",
  "            if (arr[j] > arr[j + 1]) {",
  "                int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;",
  "                swapped = 1;",
  "            }",
  "        }",
  "        if (!swapped) break;",
  "    }",
  "}",
  "",
  "// ── d. Quick Sort ───────────────────────────────────────",
  "// Time: O(n log n) avg, O(n^2) worst | Space: O(log n)",
  "int partition(int arr[], int low, int high) {",
  "    int pivot = arr[high], i = low - 1;",
  "    for (int j = low; j < high; j++) {",
  "        if (arr[j] < pivot) {",
  "            i++;",
  "            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;",
  "        }",
  "    }",
  "    int tmp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = tmp;",
  "    return i + 1;",
  "}",
  "void quickSort(int arr[], int low, int high) {",
  "    if (low < high) {",
  "        int pi = partition(arr, low, high);",
  "        quickSort(arr, low, pi - 1);",
  "        quickSort(arr, pi + 1, high);",
  "    }",
  "}",
  "",
  "// ── e. Bucket Sort ─────────────────────────────────────",
  "// Time: O(n + k) avg | Space: O(n + k)",
  "void bucketSort(float arr[], int n) {",
  "    float* bucket[MAX];",
  "    int bcount[MAX];",
  "    for (int i = 0; i < n; i++) { bucket[i] = malloc(n * sizeof(float)); bcount[i] = 0; }",
  "    for (int i = 0; i < n; i++) {",
  "        int idx = (int)(n * arr[i]);",
  "        bucket[idx][bcount[idx]++] = arr[i];",
  "    }",
  "    // Sort each bucket (insertion sort)",
  "    for (int i = 0; i < n; i++) {",
  "        for (int j = 1; j < bcount[i]; j++) {",
  "            float key = bucket[i][j]; int k = j - 1;",
  "            while (k >= 0 && bucket[i][k] > key) { bucket[i][k+1] = bucket[i][k]; k--; }",
  "            bucket[i][k+1] = key;",
  "        }",
  "    }",
  "    int idx = 0;",
  "    for (int i = 0; i < n; i++)",
  "        for (int j = 0; j < bcount[i]; j++) arr[idx++] = bucket[i][j];",
  "    for (int i = 0; i < n; i++) free(bucket[i]);",
  "}",
  "",
  "// ── f. Radix Sort ──────────────────────────────────────",
  "// Time: O(d*(n+k)) | Space: O(n+k)",
  "void countSortRadix(int arr[], int n, int exp) {",
  "    int output[MAX], count[10] = {0};",
  "    for (int i = 0; i < n; i++) count[(arr[i]/exp)%10]++;",
  "    for (int i = 1; i < 10; i++) count[i] += count[i-1];",
  "    for (int i = n-1; i >= 0; i--) { output[--count[(arr[i]/exp)%10]] = arr[i]; }",
  "    for (int i = 0; i < n; i++) arr[i] = output[i];",
  "}",
  "void radixSort(int arr[], int n) {",
  "    int mx = arr[0];",
  "    for (int i = 1; i < n; i++) if (arr[i] > mx) mx = arr[i];",
  "    for (int exp = 1; mx/exp > 0; exp *= 10)",
  "        countSortRadix(arr, n, exp);",
  "}",
  "",
  "// ── g. Heap Sort ───────────────────────────────────────",
  "// Time: O(n log n) all cases | Space: O(1)",
  "void heapify(int arr[], int n, int i) {",
  "    int largest = i, l = 2*i+1, r = 2*i+2;",
  "    if (l < n && arr[l] > arr[largest]) largest = l;",
  "    if (r < n && arr[r] > arr[largest]) largest = r;",
  "    if (largest != i) {",
  "        int tmp = arr[i]; arr[i] = arr[largest]; arr[largest] = tmp;",
  "        heapify(arr, n, largest);",
  "    }",
  "}",
  "void heapSort(int arr[], int n) {",
  "    for (int i = n/2-1; i >= 0; i--) heapify(arr, n, i);",
  "    for (int i = n-1; i > 0; i--) {",
  "        int tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;",
  "        heapify(arr, i, 0);",
  "    }",
  "}",
  "",
  "// ── h. Merge Sort ──────────────────────────────────────",
  "// Time: O(n log n) all cases | Space: O(n)",
  "void merge(int arr[], int l, int m, int r) {",
  "    int n1 = m-l+1, n2 = r-m;",
  "    int L[MAX], R[MAX];",
  "    for (int i = 0; i < n1; i++) L[i] = arr[l+i];",
  "    for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];",
  "    int i = 0, j = 0, k = l;",
  "    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];",
  "    while (i < n1) arr[k++] = L[i++];",
  "    while (j < n2) arr[k++] = R[j++];",
  "}",
  "void mergeSort(int arr[], int l, int r) {",
  "    if (l < r) {",
  "        int m = (l + r) / 2;",
  "        mergeSort(arr, l, m);",
  "        mergeSort(arr, m+1, r);",
  "        merge(arr, l, m, r);",
  "    }",
  "}",
  "",
  "// ── Utility: Print Array ───────────────────────────────",
  "void printArr(int arr[], int n) {",
  "    for (int i = 0; i < n; i++) printf(\"%d \", arr[i]);",
  "    printf(\"\\n\");",
  "}",
  "",
  "int main() {",
  "    int a[] = {64, 25, 12, 22, 11};",
  "    int n = 5;",
  "",
  "    int arr1[MAX]; memcpy(arr1, a, n*sizeof(int));",
  "    insertionSort(arr1, n);",
  "    printf(\"Insertion Sort: \"); printArr(arr1, n);",
  "",
  "    int arr2[MAX]; memcpy(arr2, a, n*sizeof(int));",
  "    selectionSort(arr2, n);",
  "    printf(\"Selection Sort: \"); printArr(arr2, n);",
  "",
  "    int arr3[MAX]; memcpy(arr3, a, n*sizeof(int));",
  "    bubbleSort(arr3, n);",
  "    printf(\"Bubble Sort:    \"); printArr(arr3, n);",
  "",
  "    int arr4[MAX]; memcpy(arr4, a, n*sizeof(int));",
  "    quickSort(arr4, 0, n-1);",
  "    printf(\"Quick Sort:     \"); printArr(arr4, n);",
  "",
  "    float fa[] = {0.897, 0.565, 0.656, 0.123, 0.665};",
  "    bucketSort(fa, n);",
  "    printf(\"Bucket Sort: \");",
  "    for (int i = 0; i < n; i++) printf(\"%.3f \", fa[i]); printf(\"\\n\");",
  "",
  "    int arr6[MAX]; memcpy(arr6, a, n*sizeof(int));",
  "    radixSort(arr6, n);",
  "    printf(\"Radix Sort:     \"); printArr(arr6, n);",
  "",
  "    int arr7[MAX]; memcpy(arr7, a, n*sizeof(int));",
  "    heapSort(arr7, n);",
  "    printf(\"Heap Sort:      \"); printArr(arr7, n);",
  "",
  "    int arr8[MAX]; memcpy(arr8, a, n*sizeof(int));",
  "    mergeSort(arr8, 0, n-1);",
  "    printf(\"Merge Sort:     \"); printArr(arr8, n);",
  "",
  "    return 0;",
  "}"
];

const exp2Code = [
  "#include <stdio.h>",
  "",
  "// ── Linear Search ─────────────────────────────────────────",
  "// Time: O(n) worst/avg, O(1) best | Space: O(1)",
  "int linearSearch(int arr[], int n, int target) {",
  "    for (int i = 0; i < n; i++)",
  "        if (arr[i] == target) return i;",
  "    return -1;",
  "}",
  "",
  "// ── Binary Search (Iterative) ────────────────────────────",
  "// Time: O(log n) worst/avg, O(1) best | Space: O(1)",
  "// Precondition: array must be sorted",
  "int binarySearch(int arr[], int n, int target) {",
  "    int low = 0, high = n - 1;",
  "    while (low <= high) {",
  "        int mid = low + (high - low) / 2;",
  "        if (arr[mid] == target)  return mid;",
  "        else if (arr[mid] < target) low = mid + 1;",
  "        else                        high = mid - 1;",
  "    }",
  "    return -1;",
  "}",
  "",
  "// ── Binary Search (Recursive) ────────────────────────────",
  "// Time: O(log n) | Space: O(log n) due to call stack",
  "int binarySearchRec(int arr[], int low, int high, int target) {",
  "    if (low > high) return -1;",
  "    int mid = low + (high - low) / 2;",
  "    if (arr[mid] == target)  return mid;",
  "    if (arr[mid] < target)   return binarySearchRec(arr, mid+1, high, target);",
  "    return binarySearchRec(arr, low, mid-1, target);",
  "}",
  "",
  "int main() {",
  "    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};",
  "    int n = 10, target = 23;",
  "",
  "    int res1 = linearSearch(arr, n, target);",
  "    printf(\"Linear Search: %d %s\\n\", target, res1 != -1 ? \"found\" : \"not found\");",
  "    if (res1 != -1) printf(\"  -> Index: %d\\n\", res1);",
  "",
  "    int res2 = binarySearch(arr, n, target);",
  "    printf(\"Binary Search (iterative): %d %s\\n\", target, res2 != -1 ? \"found\" : \"not found\");",
  "    if (res2 != -1) printf(\"  -> Index: %d\\n\", res2);",
  "",
  "    int res3 = binarySearchRec(arr, 0, n-1, target);",
  "    printf(\"Binary Search (recursive): %d %s\\n\", target, res3 != -1 ? \"found\" : \"not found\");",
  "    if (res3 != -1) printf(\"  -> Index: %d\\n\", res3);",
  "",
  "    return 0;",
  "}"
];

const exp3Code = [
  "#include <stdio.h>",
  "#include <limits.h>",
  "",
  "#define MAX 10",
  "",
  "// Matrix Chain Multiplication using Dynamic Programming",
  "// Time: O(n^3) | Space: O(n^2)",
  "// p[] = dimensions array; p[i-1] x p[i] is the i-th matrix",
  "",
  "int matrixChainOrder(int p[], int n) {",
  "    // m[i][j] = min multiplications to compute matrix i..j",
  "    int m[MAX][MAX] = {0};",
  "    int s[MAX][MAX] = {0};  // split position",
  "",
  "    // chain length l",
  "    for (int l = 2; l < n; l++) {",
  "        for (int i = 1; i < n - l + 1; i++) {",
  "            int j = i + l - 1;",
  "            m[i][j] = INT_MAX;",
  "            for (int k = i; k < j; k++) {",
  "                int cost = m[i][k] + m[k+1][j]",
  "                         + p[i-1] * p[k] * p[j];",
  "                if (cost < m[i][j]) {",
  "                    m[i][j] = cost;",
  "                    s[i][j] = k;",
  "                }",
  "            }",
  "        }",
  "    }",
  "",
  "    // Print the DP table",
  "    printf(\"Minimum multiplications table:\\n\");",
  "    for (int i = 1; i < n; i++) {",
  "        for (int j = 1; j < n; j++)",
  "            printf(\"%8d \", (i <= j) ? m[i][j] : 0);",
  "        printf(\"\\n\");",
  "    }",
  "",
  "    return m[1][n-1];",
  "}",
  "",
  "// Print optimal parenthesization",
  "void printParens(int s[][MAX], int i, int j) {",
  "    if (i == j) { printf(\"A%d\", i); return; }",
  "    printf(\"(\");",
  "    printParens(s, i, s[i][j]);",
  "    printParens(s, s[i][j]+1, j);",
  "    printf(\")\");",
  "}",
  "",
  "int main() {",
  "    // Example: 4 matrices A1(30x35), A2(35x15), A3(15x5), A4(5x10)",
  "    int p[] = {30, 35, 15, 5, 10};",
  "    int n = sizeof(p) / sizeof(p[0]);",
  "",
  "    printf(\"Matrix dimensions:\\n\");",
  "    for (int i = 1; i < n; i++)",
  "        printf(\"  A%d: %d x %d\\n\", i, p[i-1], p[i]);",
  "",
  "    int result = matrixChainOrder(p, n);",
  "    printf(\"\\nMinimum number of scalar multiplications: %d\\n\", result);",
  "",
  "    return 0;",
  "}"
];

const exp4Code = [
  "#include <stdio.h>",
  "#include <string.h>",
  "",
  "#define MAX 100",
  "",
  "// LCS using Dynamic Programming",
  "// Time: O(m*n) | Space: O(m*n)",
  "int lcs(char *X, char *Y, int m, int n) {",
  "    int dp[MAX][MAX] = {0};",
  "",
  "    for (int i = 1; i <= m; i++) {",
  "        for (int j = 1; j <= n; j++) {",
  "            if (X[i-1] == Y[j-1])",
  "                dp[i][j] = dp[i-1][j-1] + 1;",
  "            else",
  "                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];",
  "        }",
  "    }",
  "",
  "    // Print the LCS string by backtracking",
  "    int idx = dp[m][n];",
  "    char result[MAX];",
  "    result[idx] = '\\0';",
  "    int i = m, j = n;",
  "    while (i > 0 && j > 0) {",
  "        if (X[i-1] == Y[j-1]) {",
  "            result[--idx] = X[i-1];",
  "            i--; j--;",
  "        } else if (dp[i-1][j] > dp[i][j-1]) {",
  "            i--;",
  "        } else {",
  "            j--;",
  "        }",
  "    }",
  "",
  "    printf(\"LCS string: %s\\n\", result);",
  "    return dp[m][n];",
  "}",
  "",
  "int main() {",
  "    char X[] = \"AGGTAB\";",
  "    char Y[] = \"GXTXAYB\";",
  "    int m = strlen(X), n = strlen(Y);",
  "",
  "    printf(\"String X: %s\\n\", X);",
  "    printf(\"String Y: %s\\n\", Y);",
  "",
  "    int len = lcs(X, Y, m, n);",
  "    printf(\"Length of LCS: %d\\n\", len);",
  "",
  "    return 0;",
  "}"
];

const exp5Code = [
  "#include <stdio.h>",
  "#include <float.h>",
  "",
  "#define MAX 10",
  "",
  "// Optimal BST using Dynamic Programming",
  "// Time: O(n^3) | Space: O(n^2)",
  "",
  "float cost[MAX][MAX];    // cost[i][j] = optimal cost for keys i..j",
  "int   root[MAX][MAX];    // root of optimal BST for keys i..j",
  "float w[MAX][MAX];       // w[i][j] = sum of probabilities p[i..j] + q[i..j]",
  "",
  "void optimalBST(float p[], float q[], int n) {",
  "    // p[i] = probability of key i being searched (1-indexed)",
  "    // q[i] = probability of dummy key (miss) between key i and i+1",
  "",
  "    // Initialize for single keys and no-key ranges",
  "    for (int i = 0; i <= n; i++) {",
  "        cost[i+1][i] = 0;",
  "        w[i+1][i]    = q[i];",
  "    }",
  "",
  "    // chain length l",
  "    for (int l = 1; l <= n; l++) {",
  "        for (int i = 1; i <= n - l + 1; i++) {",
  "            int j = i + l - 1;",
  "            cost[i][j] = FLT_MAX;",
  "            w[i][j]    = w[i][j-1] + p[j] + q[j];",
  "",
  "            for (int r = i; r <= j; r++) {",
  "                float c = cost[i][r-1] + cost[r+1][j] + w[i][j];",
  "                if (c < cost[i][j]) {",
  "                    cost[i][j] = c;",
  "                    root[i][j] = r;",
  "                }",
  "            }",
  "        }",
  "    }",
  "}",
  "",
  "int main() {",
  "    // 4 keys with search probabilities",
  "    int n = 4;",
  "    float p[] = {0, 0.15, 0.10, 0.05, 0.10};  // p[1..4]",
  "    float q[] = {0.05, 0.10, 0.05, 0.05, 0.05}; // q[0..4]",
  "",
  "    optimalBST(p, q, n);",
  "",
  "    printf(\"Optimal BST cost: %.2f\\n\", cost[1][n]);",
  "    printf(\"Root of optimal BST: key %d\\n\", root[1][n]);",
  "",
  "    printf(\"\\nCost table:\\n\");",
  "    for (int i = 1; i <= n; i++) {",
  "        for (int j = 1; j <= n; j++)",
  "            printf(\"%.2f \", (i <= j) ? cost[i][j] : 0.0f);",
  "        printf(\"\\n\");",
  "    }",
  "",
  "    return 0;",
  "}"
];

const exp6Code = [
  "#include <stdio.h>",
  "#include <stdlib.h>",
  "#include <string.h>",
  "",
  "#define MAX_TREE_HT 100",
  "",
  "// Min-Heap node",
  "struct MinHeapNode {",
  "    char data;",
  "    unsigned freq;",
  "    struct MinHeapNode *left, *right;",
  "};",
  "",
  "struct MinHeap {",
  "    unsigned size;",
  "    unsigned capacity;",
  "    struct MinHeapNode** array;",
  "};",
  "",
  "struct MinHeapNode* newNode(char data, unsigned freq) {",
  "    struct MinHeapNode* node = malloc(sizeof(struct MinHeapNode));",
  "    node->left = node->right = NULL;",
  "    node->data = data;",
  "    node->freq = freq;",
  "    return node;",
  "}",
  "",
  "struct MinHeap* createMinHeap(unsigned cap) {",
  "    struct MinHeap* heap = malloc(sizeof(struct MinHeap));",
  "    heap->size = 0; heap->capacity = cap;",
  "    heap->array = malloc(cap * sizeof(struct MinHeapNode*));",
  "    return heap;",
  "}",
  "",
  "void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b)",
  "{ struct MinHeapNode* t = *a; *a = *b; *b = t; }",
  "",
  "void minHeapify(struct MinHeap* h, int i) {",
  "    int smallest = i, l = 2*i+1, r = 2*i+2;",
  "    if (l < (int)h->size && h->array[l]->freq < h->array[smallest]->freq) smallest = l;",
  "    if (r < (int)h->size && h->array[r]->freq < h->array[smallest]->freq) smallest = r;",
  "    if (smallest != i) { swapNodes(&h->array[smallest], &h->array[i]); minHeapify(h, smallest); }",
  "}",
  "",
  "struct MinHeapNode* extractMin(struct MinHeap* h) {",
  "    struct MinHeapNode* temp = h->array[0];",
  "    h->array[0] = h->array[--h->size];",
  "    minHeapify(h, 0);",
  "    return temp;",
  "}",
  "",
  "void insertMinHeap(struct MinHeap* h, struct MinHeapNode* node) {",
  "    int i = h->size++;",
  "    while (i && node->freq < h->array[(i-1)/2]->freq) {",
  "        h->array[i] = h->array[(i-1)/2]; i = (i-1)/2;",
  "    }",
  "    h->array[i] = node;",
  "}",
  "",
  "void buildMinHeap(struct MinHeap* h) {",
  "    for (int i = h->size/2 - 1; i >= 0; i--) minHeapify(h, i);",
  "}",
  "",
  "struct MinHeap* createAndBuildHeap(char data[], int freq[], int size) {",
  "    struct MinHeap* h = createMinHeap(size);",
  "    for (int i = 0; i < size; i++) h->array[i] = newNode(data[i], freq[i]);",
  "    h->size = size;",
  "    buildMinHeap(h);",
  "    return h;",
  "}",
  "",
  "struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {",
  "    struct MinHeap* h = createAndBuildHeap(data, freq, size);",
  "    while (h->size != 1) {",
  "        struct MinHeapNode *l = extractMin(h), *r = extractMin(h);",
  "        struct MinHeapNode *top = newNode('$', l->freq + r->freq);",
  "        top->left = l; top->right = r;",
  "        insertMinHeap(h, top);",
  "    }",
  "    return extractMin(h);",
  "}",
  "",
  "void printCodes(struct MinHeapNode* root, int arr[], int top) {",
  "    if (root->left)  { arr[top] = 0; printCodes(root->left,  arr, top+1); }",
  "    if (root->right) { arr[top] = 1; printCodes(root->right, arr, top+1); }",
  "    if (!root->left && !root->right) {",
  "        printf(\"  %c: \", root->data);",
  "        for (int i = 0; i < top; i++) printf(\"%d\", arr[i]);",
  "        printf(\"\\n\");",
  "    }",
  "}",
  "",
  "void huffmanCodes(char data[], int freq[], int size) {",
  "    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);",
  "    int arr[MAX_TREE_HT]; int top = 0;",
  "    printf(\"Huffman Codes:\\n\");",
  "    printCodes(root, arr, top);",
  "}",
  "",
  "int main() {",
  "    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};",
  "    int freq[]  = { 5,   9,   12,  13,  16,  45 };",
  "    int size = sizeof(arr) / sizeof(arr[0]);",
  "",
  "    printf(\"Character frequencies:\\n\");",
  "    for (int i = 0; i < size; i++) printf(\"  %c: %d\\n\", arr[i], freq[i]);",
  "    printf(\"\\n\");",
  "",
  "    huffmanCodes(arr, freq, size);",
  "    return 0;",
  "}"
];

const exp7Code = [
  "#include <stdio.h>",
  "#include <limits.h>",
  "#include <stdbool.h>",
  "",
  "#define V 9",
  "",
  "// Dijkstra's Single Source Shortest Path",
  "// Time: O(V^2) with adjacency matrix | O((V+E) log V) with min-heap",
  "// Space: O(V)",
  "",
  "int minDistance(int dist[], bool sptSet[]) {",
  "    int min = INT_MAX, minIdx = -1;",
  "    for (int v = 0; v < V; v++)",
  "        if (!sptSet[v] && dist[v] <= min) { min = dist[v]; minIdx = v; }",
  "    return minIdx;",
  "}",
  "",
  "void dijkstra(int graph[V][V], int src) {",
  "    int  dist[V];",
  "    int  parent[V];",
  "    bool sptSet[V];",
  "",
  "    for (int i = 0; i < V; i++) {",
  "        dist[i] = INT_MAX; sptSet[i] = false; parent[i] = -1;",
  "    }",
  "    dist[src] = 0;",
  "",
  "    for (int count = 0; count < V - 1; count++) {",
  "        int u = minDistance(dist, sptSet);",
  "        sptSet[u] = true;",
  "",
  "        for (int v = 0; v < V; v++) {",
  "            if (!sptSet[v] && graph[u][v] &&",
  "                dist[u] != INT_MAX &&",
  "                dist[u] + graph[u][v] < dist[v]) {",
  "                dist[v]   = dist[u] + graph[u][v];",
  "                parent[v] = u;",
  "            }",
  "        }",
  "    }",
  "",
  "    // Print result",
  "    printf(\"Dijkstra's Shortest Paths from vertex %d:\\n\\n\", src);",
  "    printf(\"  Vertex | Distance | Path\\n\");",
  "    printf(\"  -------|----------|-----\\n\");",
  "    for (int i = 0; i < V; i++) {",
  "        printf(\"  %6d | %8d | \", i, dist[i]);",
  "        int path[V], pcnt = 0, cur = i;",
  "        while (cur != -1) { path[pcnt++] = cur; cur = parent[cur]; }",
  "        for (int j = pcnt-1; j >= 0; j--) {",
  "            printf(\"%d\", path[j]);",
  "            if (j > 0) printf(\" -> \");",
  "        }",
  "        printf(\"\\n\");",
  "    }",
  "}",
  "",
  "int main() {",
  "    int graph[V][V] = {",
  "        {0, 4, 0, 0, 0, 0, 0, 8, 0},",
  "        {4, 0, 8, 0, 0, 0, 0,11, 0},",
  "        {0, 8, 0, 7, 0, 4, 0, 0, 2},",
  "        {0, 0, 7, 0, 9,14, 0, 0, 0},",
  "        {0, 0, 0, 9, 0,10, 0, 0, 0},",
  "        {0, 0, 4,14,10, 0, 2, 0, 0},",
  "        {0, 0, 0, 0, 0, 2, 0, 1, 6},",
  "        {8,11, 0, 0, 0, 0, 1, 0, 7},",
  "        {0, 0, 2, 0, 0, 0, 6, 7, 0}",
  "    };",
  "    dijkstra(graph, 0);",
  "    return 0;",
  "}"
];

const exp8Code = [
  "#include <stdio.h>",
  "#include <stdlib.h>",
  "#include <limits.h>",
  "",
  "#define INF INT_MAX",
  "",
  "struct Edge  { int src, dest, weight; };",
  "struct Graph { int V, E; struct Edge* edge; };",
  "",
  "struct Graph* createGraph(int V, int E) {",
  "    struct Graph* g = malloc(sizeof(struct Graph));",
  "    g->V = V; g->E = E;",
  "    g->edge = malloc(E * sizeof(struct Edge));",
  "    return g;",
  "}",
  "",
  "// Bellman-Ford Algorithm",
  "// Time: O(V * E) | Space: O(V)",
  "// Works with negative weight edges; detects negative weight cycles",
  "void bellmanFord(struct Graph* g, int src) {",
  "    int V = g->V, E = g->E;",
  "    int dist[V], parent[V];",
  "",
  "    for (int i = 0; i < V; i++) { dist[i] = INF; parent[i] = -1; }",
  "    dist[src] = 0;",
  "",
  "    // Relax all edges V-1 times",
  "    for (int i = 1; i <= V - 1; i++) {",
  "        for (int j = 0; j < E; j++) {",
  "            int u = g->edge[j].src;",
  "            int v = g->edge[j].dest;",
  "            int w = g->edge[j].weight;",
  "            if (dist[u] != INF && dist[u] + w < dist[v]) {",
  "                dist[v]   = dist[u] + w;",
  "                parent[v] = u;",
  "            }",
  "        }",
  "    }",
  "",
  "    // Check for negative-weight cycles",
  "    for (int j = 0; j < E; j++) {",
  "        int u = g->edge[j].src;",
  "        int v = g->edge[j].dest;",
  "        int w = g->edge[j].weight;",
  "        if (dist[u] != INF && dist[u] + w < dist[v]) {",
  "            printf(\"Graph contains a negative weight cycle!\\n\");",
  "            return;",
  "        }",
  "    }",
  "",
  "    // Print shortest distances",
  "    printf(\"Bellman-Ford Shortest Distances from vertex %d:\\n\\n\", src);",
  "    printf(\"  Vertex | Distance\\n\");",
  "    printf(\"  -------|----------\\n\");",
  "    for (int i = 0; i < V; i++) {",
  "        if (dist[i] == INF) printf(\"  %6d | INF\\n\", i);",
  "        else                printf(\"  %6d | %d\\n\", i, dist[i]);",
  "    }",
  "}",
  "",
  "int main() {",
  "    int V = 5, E = 8;",
  "    struct Graph* g = createGraph(V, E);",
  "",
  "    g->edge[0] = (struct Edge){0, 1, -1};",
  "    g->edge[1] = (struct Edge){0, 2,  4};",
  "    g->edge[2] = (struct Edge){1, 2,  3};",
  "    g->edge[3] = (struct Edge){1, 3,  2};",
  "    g->edge[4] = (struct Edge){1, 4,  2};",
  "    g->edge[5] = (struct Edge){3, 2,  5};",
  "    g->edge[6] = (struct Edge){3, 1,  1};",
  "    g->edge[7] = (struct Edge){4, 3, -3};",
  "",
  "    bellmanFord(g, 0);",
  "",
  "    free(g->edge);",
  "    free(g);",
  "    return 0;",
  "}"
];

const exp9Code = [
  "#include <stdio.h>",
  "#include <stdlib.h>",
  "#include <stdbool.h>",
  "",
  "#define MAX 100",
  "",
  "// Adjacency list representation",
  "struct Node  { int data; struct Node* next; };",
  "struct Graph { int V; struct Node** adj; };",
  "",
  "struct Node* newNode(int v) {",
  "    struct Node* n = malloc(sizeof(struct Node));",
  "    n->data = v; n->next = NULL; return n;",
  "}",
  "",
  "struct Graph* createGraph(int V) {",
  "    struct Graph* g = malloc(sizeof(struct Graph));",
  "    g->V = V;",
  "    g->adj = malloc(V * sizeof(struct Node*));",
  "    for (int i = 0; i < V; i++) g->adj[i] = NULL;",
  "    return g;",
  "}",
  "",
  "void addEdge(struct Graph* g, int u, int v) {",
  "    // undirected graph",
  "    struct Node* n = newNode(v); n->next = g->adj[u]; g->adj[u] = n;",
  "    n = newNode(u); n->next = g->adj[v]; g->adj[v] = n;",
  "}",
  "",
  "// ── DFS (Recursive) ──────────────────────────────────────",
  "// Time: O(V + E) | Space: O(V) recursion stack",
  "bool visited_dfs[MAX];",
  "",
  "void DFSUtil(struct Graph* g, int v) {",
  "    visited_dfs[v] = true;",
  "    printf(\"%d \", v);",
  "    for (struct Node* adj = g->adj[v]; adj; adj = adj->next)",
  "        if (!visited_dfs[adj->data])",
  "            DFSUtil(g, adj->data);",
  "}",
  "",
  "void DFS(struct Graph* g, int start) {",
  "    for (int i = 0; i < g->V; i++) visited_dfs[i] = false;",
  "    printf(\"DFS traversal from vertex %d: \", start);",
  "    DFSUtil(g, start);",
  "    printf(\"\\n\");",
  "}",
  "",
  "// ── BFS (Iterative with Queue) ───────────────────────────",
  "// Time: O(V + E) | Space: O(V)",
  "void BFS(struct Graph* g, int start) {",
  "    bool visited[MAX] = {false};",
  "    int queue[MAX], front = 0, rear = 0;",
  "",
  "    visited[start] = true;",
  "    queue[rear++] = start;",
  "",
  "    printf(\"BFS traversal from vertex %d: \", start);",
  "    while (front < rear) {",
  "        int v = queue[front++];",
  "        printf(\"%d \", v);",
  "        for (struct Node* adj = g->adj[v]; adj; adj = adj->next) {",
  "            if (!visited[adj->data]) {",
  "                visited[adj->data] = true;",
  "                queue[rear++] = adj->data;",
  "            }",
  "        }",
  "    }",
  "    printf(\"\\n\");",
  "}",
  "",
  "int main() {",
  "    struct Graph* g = createGraph(6);",
  "    addEdge(g, 0, 1);",
  "    addEdge(g, 0, 2);",
  "    addEdge(g, 1, 3);",
  "    addEdge(g, 2, 4);",
  "    addEdge(g, 3, 5);",
  "    addEdge(g, 4, 5);",
  "",
  "    printf(\"Graph has %d vertices and edges:\\n\", g->V);",
  "    printf(\"  0-1, 0-2, 1-3, 2-4, 3-5, 4-5\\n\\n\");",
  "",
  "    DFS(g, 0);",
  "    BFS(g, 0);",
  "",
  "    return 0;",
  "}"
];

const exp10Code = [
  "#include <stdio.h>",
  "",
  "#define MAX_ITEMS   100",
  "#define MAX_WEIGHT  1000",
  "",
  "// 0/1 Knapsack using Dynamic Programming",
  "// Time: O(n * W) | Space: O(n * W)",
  "// n = number of items, W = knapsack capacity",
  "",
  "int max(int a, int b) { return (a > b) ? a : b; }",
  "",
  "int knapsack(int W, int wt[], int val[], int n) {",
  "    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];",
  "",
  "    // Build dp table bottom-up",
  "    for (int i = 0; i <= n; i++) {",
  "        for (int w = 0; w <= W; w++) {",
  "            if (i == 0 || w == 0)",
  "                dp[i][w] = 0;",
  "            else if (wt[i-1] <= w)",
  "                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]],",
  "                               dp[i-1][w]);",
  "            else",
  "                dp[i][w] = dp[i-1][w];",
  "        }",
  "    }",
  "",
  "    // Traceback: find which items are included",
  "    int res = dp[n][W], w = W;",
  "    printf(\"Items included in knapsack:\\n\");",
  "    printf(\"  Item | Weight | Value\\n\");",
  "    printf(\"  -----|--------|------\\n\");",
  "    for (int i = n; i > 0 && res > 0; i--) {",
  "        if (res != dp[i-1][w]) {",
  "            printf(\"  %4d | %6d | %5d\\n\", i, wt[i-1], val[i-1]);",
  "            res -= val[i-1];",
  "            w   -= wt[i-1];",
  "        }",
  "    }",
  "",
  "    return dp[n][W];",
  "}",
  "",
  "int main() {",
  "    int val[] = {60, 100, 120};",
  "    int wt[]  = {10,  20,  30};",
  "    int W = 50;",
  "    int n = sizeof(val) / sizeof(val[0]);",
  "",
  "    printf(\"0/1 Knapsack Problem\\n\");",
  "    printf(\"Capacity W = %d\\n\\n\", W);",
  "    printf(\"Available items:\\n\");",
  "    printf(\"  Item | Weight | Value\\n\");",
  "    printf(\"  -----|--------|------\\n\");",
  "    for (int i = 0; i < n; i++)",
  "        printf(\"  %4d | %6d | %5d\\n\", i+1, wt[i], val[i]);",
  "    printf(\"\\n\");",
  "",
  "    int maxVal = knapsack(W, wt, val, n);",
  "    printf(\"\\nMaximum value achievable: %d\\n\", maxVal);",
  "",
  "    return 0;",
  "}"
];

// ─── COMPLEXITY TABLES ────────────────────────────────────────

function exp1ComplexityTable() {
  return complexityTable(
    ["Algorithm", "Best", "Average", "Worst", "Space"],
    [
      ["Insertion Sort", "O(n)", "O(n²)", "O(n²)", "O(1)"],
      ["Selection Sort", "O(n²)", "O(n²)", "O(n²)", "O(1)"],
      ["Bubble Sort", "O(n)", "O(n²)", "O(n²)", "O(1)"],
      ["Quick Sort", "O(n log n)", "O(n log n)", "O(n²)", "O(log n)"],
      ["Bucket Sort", "O(n+k)", "O(n+k)", "O(n²)", "O(n+k)"],
      ["Radix Sort", "O(d·n)", "O(d·(n+k))", "O(d·(n+k))", "O(n+k)"],
      ["Heap Sort", "O(n log n)", "O(n log n)", "O(n log n)", "O(1)"],
      ["Merge Sort", "O(n log n)", "O(n log n)", "O(n log n)", "O(n)"],
    ]
  );
}

function exp2ComplexityTable() {
  return complexityTable(
    ["Algorithm", "Best", "Average", "Worst", "Space"],
    [
      ["Linear Search", "O(1)", "O(n)", "O(n)", "O(1)"],
      ["Binary Search (Iter.)", "O(1)", "O(log n)", "O(log n)", "O(1)"],
      ["Binary Search (Rec.)", "O(1)", "O(log n)", "O(log n)", "O(log n)"],
    ]
  );
}

function exp3ComplexityTable() {
  return complexityTable(
    ["Metric", "Complexity"],
    [
      ["Time Complexity", "O(n³) — three nested loops over n matrices"],
      ["Space Complexity", "O(n²) — DP table m[n][n] and split table s[n][n]"],
    ]
  );
}

function exp4ComplexityTable() {
  return complexityTable(
    ["Metric", "Complexity"],
    [
      ["Time Complexity", "O(m × n) — filling the (m+1) × (n+1) DP table"],
      ["Space Complexity", "O(m × n) — DP table storage"],
      ["Backtracking (print LCS)", "O(m + n)"],
    ]
  );
}

function exp5ComplexityTable() {
  return complexityTable(
    ["Metric", "Complexity"],
    [
      ["Time Complexity", "O(n³) — three nested loops"],
      ["Space Complexity", "O(n²) — cost, root, and w tables"],
    ]
  );
}

function exp6ComplexityTable() {
  return complexityTable(
    ["Step", "Complexity"],
    [
      ["Build min-heap", "O(n)"],
      ["Extract min", "O(log n) per operation"],
      ["Build Huffman tree", "O(n log n) — n-1 merges, each O(log n)"],
      ["Overall Time", "O(n log n)"],
      ["Space Complexity", "O(n)"],
    ]
  );
}

function exp7ComplexityTable() {
  return complexityTable(
    ["Implementation", "Time", "Space"],
    [
      ["Adjacency Matrix + Linear Search", "O(V²)", "O(V)"],
      ["Adjacency List + Min Heap", "O((V+E) log V)", "O(V)"],
    ]
  );
}

function exp8ComplexityTable() {
  return complexityTable(
    ["Metric", "Detail"],
    [
      ["Time Complexity", "O(V × E)"],
      ["Outer loop", "V-1 iterations"],
      ["Inner loop", "E edge relaxations"],
      ["Space Complexity", "O(V) — dist[] and parent[] arrays"],
      ["Advantage", "Handles negative weight edges; detects negative cycles"],
    ]
  );
}

function exp9ComplexityTable() {
  return complexityTable(
    ["Algorithm", "Adjacency List", "Adjacency Matrix", "Space"],
    [
      ["DFS", "O(V+E)", "O(V²)", "O(V)"],
      ["BFS", "O(V+E)", "O(V²)", "O(V)"],
    ]
  );
}

function exp10ComplexityTable() {
  return complexityTable(
    ["Metric", "Complexity"],
    [
      ["Time Complexity", "O(n × W)"],
      ["Space Complexity", "O(n × W) — for the DP table"],
      ["Note", "Pseudo-polynomial time; NP-Hard in general"],
    ]
  );
}

// ─── INDEX TABLE ─────────────────────────────────────────────

function indexTable() {
  const headerRow = new TableRow({
    tableHeader: true,
    children: ["S.No.", "Experiment", "Date", "Signature"].map((h, i) => {
      const widths = [600, 7200, 900, 660];
      return new TableCell({
        borders,
        width: { size: widths[i], type: WidthType.DXA },
        shading: { fill: "2E75B6", type: ShadingType.CLEAR },
        margins: { top: 100, bottom: 100, left: 120, right: 120 },
        verticalAlign: VerticalAlign.CENTER,
        children: [new Paragraph({
          alignment: AlignmentType.CENTER,
          children: [new TextRun({ text: h, bold: true, color: "FFFFFF", size: 20, font: "Arial" })]
        })]
      });
    })
  });

  const experiments = [
    "WAP to implement the following using array as data structure and analyze its time Complexity. a. Insertion sort b. Selection sort c. Bubble sort d. Quick sort e. Bucket sort f. Radix sort g. Heap sort h. Merge sort",
    "WAP to implement Linear and Binary Search and analyze its time complexity.",
    "WAP to implement Matrix Chain Multiplication and analyze its time complexity.",
    "WAP to implement Longest Common Subsequence Problem and analyze its time Complexity.",
    "WAP to implement Optimal Binary Search Tree Problem and analyze its time complexity.",
    "WAP to implement Huffman Coding and analyze its time complexity.",
    "WAP to implement Dijkstra's Algorithm and analyze its time complexity.",
    "WAP to implement Bellman Ford Algorithm and analyze its time complexity.",
    "WAP to implement DFS and BFS and analyze their time complexities.",
    "WAP to Implement 0/1 knapsack using dynamic programming."
  ];

  const dataRows = experiments.map((exp, i) => {
    const widths = [600, 7200, 900, 660];
    const cells = [String(i + 1), exp, "", ""].map((text, ci) =>
      new TableCell({
        borders,
        width: { size: widths[ci], type: WidthType.DXA },
        shading: { fill: i % 2 === 0 ? "EBF3FB" : "FFFFFF", type: ShadingType.CLEAR },
        margins: { top: 80, bottom: 80, left: 120, right: 120 },
        children: [new Paragraph({
          alignment: ci === 0 ? AlignmentType.CENTER : AlignmentType.LEFT,
          children: [new TextRun({ text, size: 18, font: "Arial", color: DARK_GRAY })]
        })]
      })
    );
    return new TableRow({ children: cells });
  });

  return new Table({
    width: { size: 9360, type: WidthType.DXA },
    columnWidths: [600, 7200, 900, 660],
    rows: [headerRow, ...dataRows]
  });
}

// ─── TITLE PAGE ───────────────────────────────────────────────

function titlePage() {
  return [
    spacer(200),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 80 },
      children: [new TextRun({ text: "MADHAV INSTITUTE OF TECHNOLOGY & SCIENCE, GWALIOR (M.P.), INDIA", bold: true, size: 26, font: "Arial", color: BLUE })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 60 },
      children: [new TextRun({ text: "माधव प्रौद्योगिकी एवं विज्ञान संस्थान, ग्वालियर (म.प्र.), भारत", size: 22, font: "Arial", color: BLUE })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 40 },
      children: [new TextRun({ text: "(Deemed to be University)", size: 20, font: "Arial", color: "7030A0" })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 200 },
      children: [new TextRun({ text: "NAAC ACCREDITED WITH A++ GRADE", bold: true, size: 18, font: "Arial", color: "C00000" })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 240, after: 240 },
      border: { top: { style: BorderStyle.SINGLE, size: 6, color: LIGHT_BLUE }, bottom: { style: BorderStyle.SINGLE, size: 6, color: LIGHT_BLUE } },
      children: [new TextRun({ text: "DAA Lab Report", bold: true, size: 48, font: "Arial", color: BLUE })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 160, after: 80 },
      children: [new TextRun({ text: "Subject Code: 15242207", bold: true, size: 28, font: "Arial", color: LIGHT_BLUE })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 80, after: 80 },
      children: [new TextRun({ text: "Submitted for Major Evaluation", size: 22, font: "Arial", color: DARK_GRAY })]
    }),
    spacer(80),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 80, after: 40 },
      children: [new TextRun({ text: "Bachelor of Technology", bold: true, size: 32, font: "Arial", color: BLUE })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 40 },
      children: [new TextRun({ text: "in", size: 22, font: "Arial", color: DARK_GRAY })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 120 },
      children: [new TextRun({ text: "Computer Science & Engineering", bold: true, size: 32, font: "Arial", color: BLUE })]
    }),
    spacer(80),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 80, after: 40 },
      children: [new TextRun({ text: "Submitted By", bold: true, size: 24, font: "Arial", color: LIGHT_BLUE })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 40, after: 20 },
      children: [new TextRun({ text: "Aditya Prakash", size: 24, font: "Arial", color: DARK_GRAY })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 120 },
      children: [new TextRun({ text: "BTCS24O1013", bold: true, size: 22, font: "Arial", color: DARK_GRAY })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 80, after: 40 },
      children: [new TextRun({ text: "Submitted To", bold: true, size: 24, font: "Arial", color: LIGHT_BLUE })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 40, after: 20 },
      children: [new TextRun({ text: "Dr. Ranjeet Kumar Singh", bold: true, size: 22, font: "Arial", color: DARK_GRAY })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 20 },
      children: [new TextRun({ text: "Assistant Professor", size: 20, font: "Arial", color: DARK_GRAY })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 0, after: 120 },
      children: [new TextRun({ text: "Department of Computer Science & Engineering", bold: true, size: 20, font: "Arial", color: DARK_GRAY })]
    }),
    new Paragraph({
      alignment: AlignmentType.CENTER,
      spacing: { before: 80, after: 0 },
      children: [new TextRun({ text: "Jan – May 2026", bold: true, size: 24, font: "Arial", color: BLUE })]
    }),
    pageBreak()
  ];
}

// ─── BUILD DOCUMENT ──────────────────────────────────────────

const experiments = [
  {
    num: 1,
    q: "WAP to implement the following using array as data structure and analyze its time Complexity. a. Insertion sort  b. Selection sort  c. Bubble sort  d. Quick sort  e. Bucket sort  f. Radix sort  g. Heap sort  h. Merge sort",
    code: exp1Code,
    table: exp1ComplexityTable(),
    note: "All sorting algorithms are implemented in C using arrays as the primary data structure."
  },
  {
    num: 2,
    q: "WAP to implement Linear and Binary Search and analyze its time complexity.",
    code: exp2Code,
    table: exp2ComplexityTable(),
    note: "Binary Search requires the array to be sorted. The iterative version uses O(1) space, while the recursive version uses O(log n) stack space."
  },
  {
    num: 3,
    q: "WAP to implement Matrix Chain Multiplication and analyze its time complexity.",
    code: exp3Code,
    table: exp3ComplexityTable(),
    note: "The bottom-up DP fills subproblems of increasing chain length. The split table s[][] is used to reconstruct the optimal parenthesization."
  },
  {
    num: 4,
    q: "WAP to implement Longest Common Subsequence Problem and analyze its time Complexity.",
    code: exp4Code,
    table: exp4ComplexityTable(),
    note: "Backtracking reconstructs the actual LCS string from the DP table in O(m + n) time after the table is built."
  },
  {
    num: 5,
    q: "WAP to implement Optimal Binary Search Tree Problem and analyze its time complexity.",
    code: exp5Code,
    table: exp5ComplexityTable(),
    note: "Three DP tables are maintained: cost[][], root[][], and weight table w[][]. The algorithm minimizes the total expected search cost."
  },
  {
    num: 6,
    q: "WAP to implement Huffman Coding and analyze its time complexity.",
    code: exp6Code,
    table: exp6ComplexityTable(),
    note: "Huffman coding is a greedy algorithm. The min-heap ensures the two nodes with lowest frequency are always merged first, producing an optimal prefix-free code."
  },
  {
    num: 7,
    q: "WAP to implement Dijkstra's Algorithm and analyze its time complexity.",
    code: exp7Code,
    table: exp7ComplexityTable(),
    note: "This implementation uses an adjacency matrix with linear search for the minimum distance vertex, giving O(V²) time. For sparse graphs, an adjacency list with min-heap achieves O((V+E) log V)."
  },
  {
    num: 8,
    q: "WAP to implement Bellman Ford Algorithm and analyze its time complexity.",
    code: exp8Code,
    table: exp8ComplexityTable(),
    note: "Unlike Dijkstra's algorithm, Bellman-Ford correctly handles graphs with negative weight edges and can detect negative weight cycles."
  },
  {
    num: 9,
    q: "WAP to implement DFS and BFS and analyze their time complexities.",
    code: exp9Code,
    table: exp9ComplexityTable(),
    note: "DFS uses a recursion stack (implicit), while BFS uses an explicit queue. Both visit each vertex and edge exactly once in an adjacency list representation."
  },
  {
    num: 10,
    q: "WAP to Implement 0/1 knapsack using dynamic programming.",
    code: exp10Code,
    table: exp10ComplexityTable(),
    note: "The 0/1 Knapsack is NP-Hard in the general case, but this DP solution runs in pseudo-polynomial time O(n × W). The traceback identifies which items are selected."
  }
];

const children = [
  ...titlePage(),

  // INDEX
  heading1("INDEX"),
  spacer(80),
  indexTable(),
  pageBreak(),
];

// Add each experiment
experiments.forEach((exp, idx) => {
  children.push(
    sectionLabel(exp.num, ""),
    new Paragraph({
      spacing: { before: 0, after: 200 },
      border: { bottom: { style: BorderStyle.SINGLE, size: 6, color: LIGHT_BLUE, space: 4 } },
      children: [new TextRun({ text: `Experiment ${exp.num}`, bold: true, color: BLUE, size: 32, font: "Arial" })]
    }),
    spacer(80),
    question(exp.q),
    spacer(80),
    solutionLabel(),
    spacer(80),
    codeBlock(exp.code),
    spacer(160),
    new Paragraph({
      spacing: { before: 80, after: 80 },
      children: [new TextRun({ text: "Time Complexity Analysis", bold: true, size: 24, font: "Arial", color: BLUE })]
    }),
    spacer(40),
    exp.table,
    spacer(80),
    body(exp.note, { italic: true, color: "555555" }),
  );
  if (idx < experiments.length - 1) children.push(pageBreak());
});

const doc = new Document({
  styles: {
    default: {
      document: { run: { font: "Arial", size: 22 } }
    },
    paragraphStyles: [
      {
        id: "Heading1", name: "Heading 1", basedOn: "Normal", next: "Normal", quickFormat: true,
        run: { size: 32, bold: true, font: "Arial", color: BLUE },
        paragraph: { spacing: { before: 360, after: 200 }, outlineLevel: 0 }
      }
    ]
  },
  sections: [{
    properties: {
      page: {
        size: { width: 11906, height: 16838 },
        margin: { top: 1440, right: 1260, bottom: 1440, left: 1440 }
      }
    },
    headers: {
      default: new Header({
        children: [
          new Paragraph({
            border: { bottom: { style: BorderStyle.SINGLE, size: 4, color: LIGHT_BLUE, space: 4 } },
            spacing: { before: 0, after: 120 },
            children: [
              new TextRun({ text: "DAA Lab Report  |  Subject Code: 15242207  |  Aditya Prakash  |  BTCS24O1013", size: 18, font: "Arial", color: "888888" })
            ]
          })
        ]
      })
    },
    footers: {
      default: new Footer({
        children: [
          new Paragraph({
            border: { top: { style: BorderStyle.SINGLE, size: 4, color: LIGHT_BLUE, space: 4 } },
            spacing: { before: 120, after: 0 },
            alignment: AlignmentType.CENTER,
            children: [
              new TextRun({ text: "Department of Computer Science & Engineering  |  MITS Gwalior  |  Page ", size: 18, font: "Arial", color: "888888" }),
              new TextRun({ children: [new PageNumber()], size: 18, font: "Arial", color: "888888" })
            ]
          })
        ]
      })
    },
    children
  }]
});

Packer.toBuffer(doc).then(buf => {
  fs.writeFileSync('/home/claude/DAA_Lab_Report.docx', buf);
  console.log('Done!');
}).catch(err => {
  console.error(err);
  process.exit(1);
});