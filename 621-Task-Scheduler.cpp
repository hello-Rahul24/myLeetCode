class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // STEP 1:
        // Count the frequency of every task.
        //
        // Example:
        // A A A B B B C
        //
        // A -> 3
        // B -> 3
        // C -> 1

        int freq[26] = {0};

        for(char task : tasks) {
            freq[task - 'A']++;
        }


        // STEP 2:
        // Find the maximum frequency.
        //
        // The task with the highest frequency creates
        // the basic structure of our schedule.
        //
        // Example:
        // A A A B B B C
        //
        // maxFreq = 3

        int maxFreq = 0;

        for(int f : freq) {
            maxFreq = max(maxFreq, f);
        }


        // STEP 3:
        // Count how many tasks have the maximum frequency.
        //
        // Example:
        // A -> 3
        // B -> 3
        // C -> 1
        //
        // Both A and B have frequency 3.
        // So countMaxFreq = 2

        int countMaxFreq = 0;

        for(int f : freq) {
            if(f == maxFreq) {
                countMaxFreq++;
            }
        }


        // STEP 4:
        // Build the minimum possible schedule length.
        //
        // The most frequent task creates:
        //
        // A _ _ A _ _ A
        //
        // If maxFreq = 3 and n = 2:
        //
        // There are (maxFreq - 1) = 2 gaps.
        //
        // Each gap has n + 1 positions including the
        // task at the beginning of the gap.
        //
        // Formula:
        //
        // (maxFreq - 1) * (n + 1)
        //
        // Then add the number of tasks having maxFreq.
        //
        // Why?
        // Because they occupy the final position.
        //
        // Example:
        // A A A
        // B B B
        // n = 2
        //
        // Schedule structure:
        //
        // A _ _ A _ _ A
        // B can occupy the final position of each block:
        //
        // A _ _ A _ _ A B
        //
        // More generally:
        //
        // (maxFreq - 1) * (n + 1) + countMaxFreq

        int calculatedTime =
            (maxFreq - 1) * (n + 1) + countMaxFreq;


        // STEP 5:
        // We cannot have fewer slots than the number of tasks.
        //
        // If there are enough different tasks to fill all
        // the idle positions, there will be NO idle time.
        //
        // Example:
        //
        // A A A B B B C C D D
        // n = 2
        //
        // We can arrange tasks without idle slots.
        //
        // Therefore:
        //
        // answer = max(total tasks, calculatedTime)

        return max((int)tasks.size(), calculatedTime);
    }
};