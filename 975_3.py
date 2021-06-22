class Solution:
    def oddEvenJumps(self, A: List[int]) -> int:
        # 思路：首先，我们可以发现下一步应该跳到哪里只与我们当前的位置与跳跃次数的奇偶性有关系。对于每一种状态，接下来可以跳到的状态一定只有一种（或者接下来不能跳跃了）。如果我们知道了不同状态之间的转移关系，我们就可以通过一次简单的遍历解决这个问题了。问题就简化为了：从索引 i 进行奇数次跳跃时，下一步应该跳到哪里去（如果有的话）。偶数次跳跃也是类似的。
        # 算法：假设当前是奇数次跳跃，让我们来搞清楚在索引 i 的位置接下来应该跳到哪里去。我们从小到大考虑数组 A 中的元素。假设当前我们正在考虑 A[j] = v，在我们已经处理过但是还未确定下一步跳跃位置的索引中（也就是 <= v 的那些）进行搜索。 如果我们找到了某些已经处理过的值 v0 = A[i] 且 i < j，那么我们就可以知道从索引 i 下一步应该跳跃到索引 j 的位置。我们可以使用单调栈来加速这个过程。我们在栈中保存所有已经处理过的索引 i ，并且时时刻刻维护这个栈中的元素是递减的。当我们增加一个新的索引 j 的时候，我们弹出栈顶比较小的索引 i < j，并且记录这些索引下一步全都会跳跃到索引 j。然后，我们就知道所有的 oddnext[i]，也就是位于索引 i 在奇数次跳跃时将会跳到的位置。使用类似的方法，我们也可以求出 evennext[i]。有了这些信息，我们就可以使用动态规划的技巧快速建立所有可达状态。
        def get_jump_location(B):
            ans = [-1] * len(A)
            stack = []  # 单调递减栈
            for i in B:
                while stack and i > stack[-1]:
                    # 弹出栈顶比较小的索引stack_top，并且记录这些索引下一步全都会跳跃到索引 i
                    stack_top = stack.pop()
                    ans[stack_top] = i
                stack.append(i)
            return ans

        N = len(A)
        # B存储的是A中index的递增排序，排序规则为A[i]大小
        B = sorted(range(N), key=lambda i: A[i])

        # odd_next[i]存储位于索引 i 在奇数次跳跃时将会跳到的位置
        # 奇数跳跃时，前进的格子必须比当前要大，所以需要index按照对应A[i]的递增排序
        odd_next = get_jump_location(B)

        # 偶数跳跃时，前进的格子必须比当前要小，所以需要index按照对应A[i]的递减排序
        B.sort(key=lambda i: -A[i])
        even_next = get_jump_location(B)

        # odd[i]/ even[i] 为DP数组，代表从i进行奇数/偶数跳跃时能否到达末尾。
        odd = [False] * N
        even = [False] * N
        # 根据题意，数组末尾默认为好的起始索引
        odd[N - 1] = even[N - 1] = True

        for i in range(N - 2, -1, -1):
            # 注意一定要从数组倒数第二位开始倒着遍历，因为只有数组末尾的初始化状态是正确的，倒着遍历才能正确转移DP状态。
            if odd_next[i] != -1:
                # 先从odd_next拿到下一个能跳到的节点。接下来要进行偶数跳跃了，查询even，看看能不能跳到末尾。
                next_index = odd_next[i]
                odd[i] = even[next_index]
            if even_next[i] != -1:
                next_index = even_next[i]
                even[i] = odd[next_index]
        
        return sum(odd)
