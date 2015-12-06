  * Trie builder
    * TrieBuilder
      * builds a trie from a sorted lexicon.
  * Tries
    * TrieBase
      * defines a common interface of tries.
      * defines useful functions that uses the common interface.
    * Array-based tries
      * Common features
        * uses invisible nodes to store values.
      * BasicTrie
        * uses a sequential search to find a specified child and it requires O(_n_) time.
        * requires 5 bytes per node.
      * TernaryTrie
        * uses a binary search to find a specified child and it requires O(log _n_) time.
        * requires 8 bytes per node.
      * DaTrie
        * uses an offset to calculate the index of a specified child and it requires O(1) time.
        * requires 8 bytes per node.
        * uses a compact variant of double-array trie.
    * Succinct ordered tree-based tries
      * Common features
        * uses a sequential search to find a specified child and it requires O(_n_) operations.
        * requires (1 + (3/8 x _A_)) bytes per node and 4 bytes per value where _A_ depends on the type of succinct bit vector.
        * uses BasicSuccinctBitVector in default.
      * SuccinctTrie<>
        * uses a level-order binary marked representation.
        * requires 1 rank() to get a value, a first child, or a next sibling.
      * LoudsTrie<>
        * uses a level-order unary degree sequence (LOUDS).
        * requires 1 rank() to get a label or a value.
        * requires 1 rank() and 1 select() to get a first child.
      * LoudsPlusTrie<>
        * uses a variant of level-order unary degree sequence (LOUDS++).
        * requires 1 rank() to get a value.
        * requires 2 calls of rank() and 1 select() to get a first child.
  * Succinct bit vectors
    * Common features
      * provides a constant time rank().
      * uses a binary search in select() and it requires O(log _n_) time.
      * requires _A_ _n_ bits for a bit vector of _n_ bits.
    * BasicSuccinctBitVector
      * uses 2 level precomputed rank().
      * requires 11/8 _n_ = 1.375 _n_ bits.
    * SimplifiedSuccinctBitVector
      * uses 1 level (flat) precomputed rank().
      * requires 2 _n_ bits.
      * speeds up succinct tries which use only rank().
    * HybridSuccinctBitVector
      * uses 2 level precomputed rank() and 1 level (flat) precomputed select().
      * requires 12/8 _n_ = 1.5 _n_ bits.
      * speeds up succinct tries which use select().
  * Key completers
    * CompleterBase
      * defines a common interface of completers.
      * provides an interactive interface to get keys starting with a specified sequence one by one.
    * BasicCompleter
      * returns keys in order of the link.
      * can collaborate with any trie.
    * ValueOrderCompleter
      * returns keys in descending order of the value.
      * collaborates with a trie arranged in max value order.