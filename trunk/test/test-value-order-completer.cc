#include <sumire/trie-builder.h>
#include <sumire/basic-trie.h>
#include <sumire/ternary-trie.h>
#include <sumire/da-trie.h>
#include <sumire/succinct-trie.h>
#include <sumire/louds-plus-trie.h>
#include <sumire/louds-trie.h>
#include <sumire/value-order-completer.h>

#include "test-tools.h"

namespace {

template <typename TRIE_TYPE>
void test_completer(const TRIE_TYPE &trie,
	const std::vector<std::string> &keys)
{
	sumire::ValueOrderCompleter completer;
	assert(completer.start(trie, trie.root()) == true);

	sumire::UInt32 key_id = keys.size();
	while (completer.next())
	{
		--key_id;
		assert(keys[key_id] == completer.key());
		assert(key_id == completer.value());
	}
}

template <typename TRIE_TYPE>
void test_trie(const sumire::TrieBase &basic_trie,
	const std::vector<std::string> &keys)
{
	TRIE_TYPE trie;
	trie.build(basic_trie);

	FIND_ALL_KEYS(trie, keys);

	test_completer(trie, keys);
}

}  // namespace

int main()
{
	std::vector<std::string> keys;
	test::Tools::read_keys("test-keys.txt", &keys);

	sumire::BasicTrie trie;
	test::Tools::build_trie(keys, &trie);

	trie.build(trie, sumire::BasicTrie::MAX_VALUE_ORDER);

	test_trie<sumire::BasicTrie>(trie, keys);
	test_trie<sumire::TernaryTrie>(trie, keys);
	test_trie<sumire::DaTrie>(trie, keys);
	test_trie<sumire::SuccinctTrie<> >(trie, keys);
	test_trie<sumire::LoudsTrie<> >(trie, keys);
	test_trie<sumire::LoudsPlusTrie<> >(trie, keys);

	return 0;
}
