<h2><a href="https://leetcode.com/problems/delete-node-in-a-linked-list/">237. Delete Node in a Linked List</a></h2><h3>Medium</h3><hr><div><p>There is a singly-linked list <code>head</code> and we want to delete a node <code>node</code> in it.</p>

<p>You are given the node to be deleted <code>node</code>. You will <strong>not be given access</strong> to the first node of <code>head</code>.</p>

<p>All the values of the linked list are <strong>unique</strong>, and it is guaranteed that the given node <code>node</code> is not the last node in the linked list.</p>

<p>Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:</p>

<ul>
	<li>The value of the given node should not exist in the linked list.</li>
	<li>The number of nodes in the linked list should decrease by one.</li>
	<li>All the values before <code>node</code> should be in the same order.</li>
	<li>All the values after <code>node</code> should be in the same order.</li>
</ul>

<p><strong>Custom testing:</strong></p>

<ul>
	<li>For the input, you should provide the entire linked list <code>head</code> and the node to be given <code>node</code>. <code>node</code> should not be the last node of the list and should be an actual node in the list.</li>
	<li>We will build the linked list and pass the node to your function.</li>
	<li>The output will be the entire list after calling your function.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node1.jpg" style="width: 400px; height: 286px;">
<pre><strong>Input:</strong> head = [4,5,1,9], node = 5
<strong>Output:</strong> [4,1,9]
<strong>Explanation: </strong>You are given the second node with value 5, the linked list should become 4 -&gt; 1 -&gt; 9 after calling your function.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node2.jpg" style="width: 400px; height: 315px;">
<pre><strong>Input:</strong> head = [4,5,1,9], node = 1
<strong>Output:</strong> [4,5,9]
<strong>Explanation: </strong>You are given the third node with value 1, the linked list should become 4 -&gt; 5 -&gt; 9 after calling your function.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the given list is in the range <code>[2, 1000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>The value of each node in the list is <strong>unique</strong>.</li>
	<li>The <code>node</code> to be deleted is <strong><mark id="d47a2e60-0a33-47e0-a1aa-0c5e3bbcc16a" data-private-id="d0d727c5-0d78-45a9-8ca7-acab7f1e6a72" data-next-private-id="c211588f-f1d7-48d5-aabe-9dee9b58d66b" class="df59810e-5ef7-4484-bd7e-04b5aa24de9e e38c8675-5c50-49d0-a832-cba12f7ca827 default-red-aa94e3d5-ab2f-4205-b74e-18ce31c7c0ce" tabindex="0">in the list</mark></strong><mark data-private-id="c211588f-f1d7-48d5-aabe-9dee9b58d66b" data-first-mark-id="d47a2e60-0a33-47e0-a1aa-0c5e3bbcc16a" data-next-private-id="b57eaf9e-a731-4596-b31b-5070eb2d6b1e" class="df59810e-5ef7-4484-bd7e-04b5aa24de9e e38c8675-5c50-49d0-a832-cba12f7ca827 default-red-aa94e3d5-ab2f-4205-b74e-18ce31c7c0ce"> and is </mark><strong><mark data-private-id="b57eaf9e-a731-4596-b31b-5070eb2d6b1e" data-first-mark-id="d47a2e60-0a33-47e0-a1aa-0c5e3bbcc16a" data-next-private-id="c486fcdc-27f6-4f83-bd11-7641e18e0665" class="df59810e-5ef7-4484-bd7e-04b5aa24de9e e38c8675-5c50-49d0-a832-cba12f7ca827 default-red-aa94e3d5-ab2f-4205-b74e-18ce31c7c0ce">not a tail</mark></strong><mark data-private-id="c486fcdc-27f6-4f83-bd11-7641e18e0665" data-first-mark-id="d47a2e60-0a33-47e0-a1aa-0c5e3bbcc16a" class="df59810e-5ef7-4484-bd7e-04b5aa24de9e e38c8675-5c50-49d0-a832-cba12f7ca827 default-red-aa94e3d5-ab2f-4205-b74e-18ce31c7c0ce"> node.</mark></li>
</ul>
</div>