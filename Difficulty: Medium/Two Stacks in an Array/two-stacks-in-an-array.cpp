class twoStacks {
    int arr[100];
    int top1;
    int top2;

public:

    twoStacks() {
        top1 = -1;
        top2 = 100;
    }

    void push1(int x) {
        if (top1 + 1 < top2) {
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x) {
        if (top1 + 1 < top2) {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1() {
        if (top1 == -1)
            return -1;

        return arr[top1--];
    }

    int pop2() {
        if (top2 == 100)
            return -1;

        return arr[top2++];
    }
};