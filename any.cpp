//ll init(vi &v, vll &tree, int node, int start, int end) {
//    if (start == end)
//        return tree[node] = v[start];
//    int mid = (start + end) / 2;
//    return tree[node] = init(v, tree, node * 2, start, mid)
//                        + init(v, tree, node * 2 + 1, mid + 1, end);
//
//}