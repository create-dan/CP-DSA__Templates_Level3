
#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> seg, lazy;

public:
    SegmentTree(int n)
    {
        seg.resize((4 * n) + 1, 0);
        lazy.resize(4 * n + 1, 0);
    }

    // Build the segment tree
    void build(int low, int high, int treeIdx, vector<int> &v);

    // Update single element
    void pointUpdate(int low, int high, int idx, int val, int treeIdx);

    // Update range
    void rangeUpdate(int low, int high, int ql, int qr, int val, int treeIdx);

    // Query for single or range of elements
    int query(int low, int high, int ql, int qr, int treeIdx);

    // Print the segment tree
    void printSegmentTree();
};

void SegmentTree ::build(int low, int high, int treeIdx, vector<int> &v)
{
    // We are at leaf node (single element)
    if (low == high)
    {
        seg[treeIdx] = v[low];
        return;
    }

    int mid = (low + high) / 2;
    build(low, mid, treeIdx * 2, v);
    build(mid + 1, high, treeIdx * 2 + 1, v);

    // While backtracking
    seg[treeIdx] = seg[treeIdx * 2] + seg[treeIdx * 2 + 1];
}

void SegmentTree::pointUpdate(int low, int high, int idx, int val, int treeIdx)
{
    if (low == high)
    {
        seg[treeIdx] += val;
        return;
    }

    int mid = (low + high) / 2;

    if (idx <= mid)
        pointUpdate(low, mid, idx, val, treeIdx * 2);
    else
        pointUpdate(mid + 1, high, idx, val, treeIdx * 2 + 1);

    seg[treeIdx] = seg[treeIdx * 2] + seg[treeIdx * 2 + 1];
}

// range madhe update kara
void SegmentTree::rangeUpdate(int low, int high, int ql, int qr, int val, int treeIdx)
{
    // If there is any pending update
    if (lazy[treeIdx])
    {
        // Nodes in current node range
        int totalNodes = high - low + 1;

        // Amount of change (update)
        int dx = lazy[treeIdx];

        lazy[treeIdx] = 0;
        seg[treeIdx] += dx * totalNodes;

        // Nodes are not leaf nodes the pass lazy update to children
        if (low != high)
        {
            lazy[treeIdx * 2] += dx;
            lazy[treeIdx * 2 + 1] += dx;
        }
    }

    if (ql > high or qr < low)
        return;

    // ql -- low -- high -- qr
    if (ql <= low and qr >= high)
    {
        int totalNodes = high - low + 1;
        int dx = val;

        seg[treeIdx] += dx * totalNodes;

        if (low != high)
        {
            lazy[treeIdx * 2] += dx;
            lazy[treeIdx * 2 + 1] += dx;
        }

        return;
    }

    int mid = (low + high) / 2;
    rangeUpdate(low, mid, ql, qr, val, treeIdx * 2);
    rangeUpdate(mid + 1, high, ql, qr, val, treeIdx * 2 + 1);

    seg[treeIdx] = seg[treeIdx * 2] + seg[treeIdx * 2 + 1];
}

// this is type 1 like ya range madhla answer aanun dya
int SegmentTree::query(int low, int high, int ql, int qr, int treeIdx)
{
    // If there is any pending update
    if (lazy[treeIdx])
    {
        // Nodes in current node range
        int totalNodes = high - low + 1;

        // Amount of change (update)
        int dx = lazy[treeIdx];

        lazy[treeIdx] = 0;
        seg[treeIdx] += dx * totalNodes;

        // Nodes are not leaf nodes the pass lazy update to children
        if (low != high)
        {
            lazy[treeIdx * 2] += dx;
            lazy[treeIdx * 2 + 1] += dx;
        }
    }

    // Given query range lies completely outside of current range
    if (ql > high or qr < low)
        return 0;

    // Complete overlap
    // ql -- low -- high -- qr
    if (ql <= low and qr >= high)
        return seg[treeIdx];

    // Partially overlap
    int mid = (low + high) / 2;

    int left = query(low, mid, ql, qr, treeIdx * 2);
    int right = query(mid + 1, high, ql, qr, treeIdx * 2 + 1);

    return left + right;
}

void SegmentTree::printSegmentTree()
{
    for (int s : seg)
    {
        cout << s << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
        }

        SegmentTree seg(n);
        seg.build(0, n - 1, 1, arr);

        // int SegmentTree::query(int low, int high, int ql, int qr, int treeIdx)
        // void SegmentTree::rangeUpdate(int low, int high, int ql, int qr, int val, int treeIdx)

        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int x, y;
                cin >> x >> y;

                cout << seg.query(0, n - 1, x, y, 1) << endl;
            }
            else
            {
                int x, y, z;
                cin >> x >> y >> z;

                seg.rangeUpdate(0, n - 1, x, t, z, 1);
            }
        }
    }
}