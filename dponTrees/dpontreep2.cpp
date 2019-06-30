Given a tree T of N nodes and an integer K, find number of different sub trees of size less than or equal to K.

First, what is a sub tree of a tree? Its a subset of nodes of original tree such that this subset is connected. Note a sub tree is different from our definition of subtree.

Always think by rooting the tree. So, say that tree is rooted at node 1. At this moment, I define S(V) as the subtree rooted at node V. This subtree definition is different from the one in problem. In S(V) all nodes in subtree of V are included.

Now, lets try to count total number of sub trees of a tree first. Then, we'll try to use same logic for solving original problem.
Lets define f(V) as number of sub trees of S(V) which include node V i.e. you choose V as root of the sub trees that we are forming. Now, in these subtrees, for each child u of node V, we have two options: whether to include them in sub tree or not. If you are including a node u, then there are f(u) ways, otherwise there is only one way(since we can't choose any nodes from S(u), otherwise the subtree we are forming will get disconnected).

So, if node V has children v1, v2, ..., vn, then we can say that . Now, is our solution complete? f(1) counts number of sub trees of T which are rooted at 1. What about sub trees which are not rooted at 1? We need to define one more function g(V) as number of subtrees of S(V) which are not rooted at V. We derive a recursion for g(V) as  i.e. for each child we add to g(V) number of ways to choose a subtree rooted at that child or not rooted at that child.

Our final answer is f(1) + g(1).

Now, onto our original problem. We are trying to count sub trees of T whose size doesn't exceed K. We need to have one more state in our DP at each node. Lets define f(V, k) as number of sub trees with k nodes and V as root. Now, we can define recurrence relation for this. Let's say for node V, there are direct children nodes v1, v2, ..., vn. Now, to form a subtree with k + 1 nodes rooted at V, lets say S(vi) contributes ai nodes. Of course, k must be  since we are forming a sub tree of size k + 1(one node is contributed by V). We should realise that f(V, k) is sum of the value  for all possible distinct sequences a1, a2, ..., an.

Now, to do this computation at node V, we will form one more DP denoted by . We say  as number of ways to choose a total of j nodes from subtrees defined by v1, v2, ..., vi. The recurrence can be defined as , i.e. we are iterating over k assuming that subtree of vi contributes k nodes.

So, finally .
And our final solution is sum  for all nodes V.

So, in terms of pseudo code we write:

f[N][K+1]

void rec(int cur_node){

     f[cur_node][1]=1
     dp_buffer[K] = {0}
     dp_buffer[0] = 1

     for(all v such that v is children of cur_node)
      rec(v)

      dp_buffer1[K] = {0}           
      for i=0 to K:
           for j=0 to K-i:
                dp_buffer1[i + j] += dp_buffer[i]*f[v][j]

      dp_buffer = dp_buffer1

     f[cur_node] = dp_buffer
}
Now, lets analyse complexity. At each node with n children, we are doing a computation of n * K2, so total complexity is O(N * K2).

Another similar problem is : We are given a tree with N nodes and a weight assigned to each node, along with a number K. The aim is to delete enough nodes from the tree so that the tree is left with precisely K leaves. The cost of such a deletion is the sum of the weights of the nodes deleted. What is the minimum cost to reduce to tree to a tree with K leaves? Now, think about the states of our DP. Derive a recurrence. Before actually proceeding to the solution give it atleast a good thinking.
