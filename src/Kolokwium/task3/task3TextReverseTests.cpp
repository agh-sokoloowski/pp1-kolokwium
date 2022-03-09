#include <iostream>
#include <algorithm>

#include <gtest/gtest.h>
#include "task3TextReverse.h"


namespace
{
    using namespace std;
    using namespace ::testing;

    template<size_t N>
    string reverseTextInCpp(char (&text)[N])
    {
        std::reverse(begin(text), end(text));
        return text;
    }
} // namespace


struct Task3TextReverseTester : public ::testing::Test
{
};

TEST_F(Task3TextReverseTester, singleShortWord)
{
    char word[] = "Powodzenia";
    const string expectedReversedText = reverseTextInCpp(word);

    reverseText(word);

    ASSERT_EQ(expectedReversedText, word);
}

TEST_F(Task3TextReverseTester, multipleCharactersMultiLine)
{
    // source: https://www.cytaty.info/autor/terrypratchett-3.htm
    char quote[] = "Uniwersytety sa skarbnicami wiedzy: studenci przychodza ze szkol przekonani, \n"
                   "ze wiedza juz prawie wszystko; po latach odchodza pewni, ze nie wiedza praktycznie niczego. \n"
                   "Gdzie sie podziewa ta wiedza? Zostaje na uniwersytecie, gdzie jest starannie suszona \n"
                   "i skladana w magazynach. \n";
    const string expectedReversedText = reverseTextInCpp(quote);

    reverseText(quote);

    ASSERT_EQ(expectedReversedText, quote);
}

TEST_F(Task3TextReverseTester, emptyTextReverse)
{
    char emptyText[] = "";

    reverseText(emptyText);

    ASSERT_EQ(emptyText, emptyText);
}