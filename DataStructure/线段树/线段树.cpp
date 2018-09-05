/*
线段树是一种二叉搜索树，与区间树相似，它将一个区间划分成一些单元区间，每个单元区间对应线段树中的一个叶结点。
对于线段树中的每一个非叶子节点[a,b]，它的左儿子表示的区间为[a,(a+b)/2]，右儿子表示的区间为[(a+b)/2+1,b]。
因此线段树是平衡二叉树，最后的子节点数目为N，即整个线段区间的长度。
建立规模为N的线段树的时间复杂度是O(NlogN)，其他操作的时间复杂度是O(logN)

可以用数组来保存 
*/
#include<vector>

// 递归方法，将nums建成线段树，存放在vlaue中，po
void build_segment_tree(std::vector<int>& value, std::vector<int>& nums, 
                        int pos, int left, int right){
    if (left == right){
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(value, nums, pos * 2 + 1, left, mid);
    build_segment_tree(value, nums, pos * 2 + 2, mid + 1, right);
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

void print_segment_tree(std::vector<int>& value, 
                        int pos, int left, int right, int layer){
    for (int i = 0; i < layer; ++i){
        printf("---");
    }
    printf("[%d %d][%d] : %d\n", left, right, pos, value[pos]);
    if (left == right){
        return;
    }
    int mid = (left + right) / 2;
    print_segment_tree(value, pos * 2 + 1, left, mid, layer + 1);
    print_segment_tree(value, pos * 2 + 2, mid + 1, right, layer +1);
}

int sum_range_segment_tree(std::vector<int>& value, 
                           int pos, int left, int right, 
                           int qleft, int qright){
    if (qleft > right || qright < left){
        return 0;
    }
    if (qleft <= left && qright >= right){
        return value[pos];
    }
    int mid = (left + right) / 2;
    return sum_range_segment_tree(value, pos * 2 + 1, left, mid, qleft, qright) +
        sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
}

void update_segment_tree(std::vector<int>& value,
                         int pos, int left, int right,
                         int index, int new_value){
    if (left == right && left == index){
        value[pos] = new_value;
        return;
    }
    int mid = (left + right) / 2;
    if (index <= mid){
        update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
    } else {
        update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
    }
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

int main(){

    std::vector<int> nums;
    for (int i =0; i < 6; ++i){
        nums.push_back(i);
    }
    std::vector<int> value;
    for (int i = 0; i < 24; ++i){
        value.push_back(0);
    }
    build_segment_tree(value, nums, 0, 0, nums.size() - 1);
    printf("segment_tree: \n");
    print_segment_tree(value, 0, 0, nums.size() - 1, 0);
    int sum_range = sum_range_segment_tree(value, 0, 0, nums.size() - 1, 2, 4);
    printf("sum_range [2, 5] = %d\n", sum_range);
    update_segment_tree(value, 0, 0, nums.size() - 1, 2, 10);
    printf("segment_tree: \n");
    print_segment_tree(value, 0, 0, nums.size() - 1, 0);

    return 0;
}