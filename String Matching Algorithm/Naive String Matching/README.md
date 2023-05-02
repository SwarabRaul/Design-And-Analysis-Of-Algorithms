# Naive String Matching

A simple algorithm for finding the occurrence of a pattern string in a text string. It works by comparing each character in the text string to the first character of the pattern string. If the characters match, the algorithm continues comparing the characters in the text string to the characters in the pattern string, one by one. If the characters do not match, the algorithm moves on to the next character in the text string. The algorithm continues this process until it finds the end of the pattern string or it reaches the end of the text string.

## Algorithm

The algorithm works by starting at the beginning of the text string and comparing each character to the first character of the pattern string. If the characters match, the algorithm continues comparing the characters in the text string to the characters in the pattern string, one by one. If the characters do not match, the algorithm moves on to the next character in the text string. The algorithm continues this process until it finds the end of the pattern string or it reaches the end of the text string.

If the algorithm finds the end of the pattern string, it returns the index of the first occurrence of the pattern string in the text string. If the algorithm reaches the end of the text string without finding the end of the pattern string, it returns -1.

Here is the **pseudocode** for the algorithm:

```less
Algorithm NaiveStringMatching(Text, Pattern)
    n = length(Text)
    m = length(Pattern)

    for i = 0 to n - m do:
        j = 0
        while j < m and Text[i + j] = Pattern[j] do:
            j = j + 1

        if j == m then:
            output "Pattern found at index: " + i
    end for

end procedure
```

An **alternative pseudocode** for the algorithm:

```less
1. Initialize a variable i to 0.
2. While i < length(Text):
    - Compare the character at Text[i] to the 1st character of the Pattern string.
    - If the characters match:
        - Compare the characters at Text[i + 1], Text[i + 2], ..., Text[i + m -1] to the characters at Pattern[1], Pattern[2], ..., Pattern[m - 1], respectively.
        - If all the characters matches, return i.
    - Increment i by 1. 
3. Return -1.
```

## Use Cases
Naive String Matching can be used to solve various problems that involve finding occurrences of a pattern string within a longer text string. Here are some use cases for Naive String Matching:

- **Text Search:** Naive String Matching can be used to search for a keyword or phrase within a large document or corpus. This can be useful in applications such as web search engines, text editors, and content management systems.

- **Data Processing:** Naive String Matching can be used to extract data from unstructured text, such as log files, emails, and social media posts. This can help in analyzing user behavior, sentiment analysis, and marketing research.

- **Security:** Naive String Matching can be used to detect malicious code or patterns in files or network traffic. This can help in intrusion detection, malware analysis, and cyber threat intelligence.

- **Genome Analysis:** Naive String Matching can be used to find matches or similarities in genetic sequences, which can aid in bioinformatics research and drug discovery.

- **Image Processing:** Naive String Matching can be used to detect patterns or features in digital images, such as recognizing faces or objects. This can be useful in applications such as image search engines, surveillance systems, and autonomous vehicles.

## Proof Of Correctness

The correctness of Naive String Matching can be proved using the following steps:

- **Initialization**
    - The algorithm initializes a variable i to 0. This is the index of the current character in the text string.
- **Maintenance**
    - The algorithm compares the character at text[i] to the first character of the pattern string. If the characters match, the algorithm continues comparing the characters in the text string to the characters in the pattern string, one by one. If the characters do not match, the algorithm moves on to the next character in the text string.
- **Termination**
    - The algorithm terminates when it finds the end of the pattern string or it reaches the end of the text string. If the algorithm finds the end of the pattern string, it returns the index of the first occurrence of the pattern string in the text string. If the algorithm reaches the end of the text string without finding the end of the pattern string, it returns -1.

## Advantages & Disadvantages

- **Advantages:**
    - Simple to understand and implement.
    - Simple to understand and implement.

- **Disadvantages:**
    - Not very efficient.
    - Can be slow for large text strings.

## Complexity

Fractional Knapsack has the following complexity characteristics:    

- **Time Complexity**
    - Best Case: $\ O(m) $, occurs when the pattern string is found at the beginning of the text string.
    - Average Case: $\ O(mn) $, occurs when the pattern string is found somewhere in the middle of the text string.
    - Worst Case: $\ O(mn) $, occurs when the pattern string is found somewhere in the middle of the text string.

- **Space Complexity:** $\ O(1) $, the algorithm does not require any additional space.

- **Stability:** The Naive String Matching algorithm is a stable algorithm because it preserves the relative order of occurrences of the pattern string within the text string.

## Conclusion

Overall, the naive string matching algorithm is a simple algorithm that can be used to find the occurrence of a pattern string in a text string. It is not very efficient, but it is a good choice for small text strings.