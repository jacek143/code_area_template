#include "vowel_game.h"
#include "gtest/gtest.h"

using vowel_game::count_vowels_in_all_substrings;

TEST(CheckIfVowelGame, worksForNoVowels) {
  EXPECT_EQ(0, count_vowels_in_all_substrings("gdfk"));
}

TEST(CheckIfVowelGame, worksForSingleVowel) {
  EXPECT_EQ(1, count_vowels_in_all_substrings("a"));
  EXPECT_EQ(1, count_vowels_in_all_substrings("E"));
}

TEST(CheckIfVowelGame, worksForTypicalExample) {
  EXPECT_EQ(16, count_vowels_in_all_substrings("baceb"));
}

TEST(CheckIfVowelGame, worksForReallyBigInput) {
  EXPECT_EQ(7811003,
            count_vowels_in_all_substrings(
                "DXqzxJrCnsAUSmkUkQCedQTcyYHIUPixMbyLKQoAKOuDDgxNWBRCrmErkNafCK"
                "eQnfBYxPahgumJclYAMPcFbizNVbuxnbnBgrbDIbmqXbZZOzzdQeItmJhiKdFY"
                "evbMMcRWdGnajOZXoaaeGlyTUhbhkifRfgftKzqNfDNQToNhQqmxBmqXtTefDL"
                "WJtEEddUsiZfYTVnCMDqjGCbgxUMDZazkVdPZglTQlZqGUEKiJbrSfUYDOKgqK"
                "hAGNphTBCmoBCwYIggUJaMPUmUlyadLhDTwTCqWeeMiiigtQOncqBtNNnANPDy"
                "ygrVBTNxYRjIBTOUmehoXkHmXwMLlpLlXdgbyvyYmkGOdWIpDsfACMMcKapxRa"
                "JOFrPeNQcZClphhAZKueMWtaAdaPBtQMKvdbbQtGsVRjdAJcNFgzezcEfEWiYo"
                "UIlXlnqFTIAKtDMFhzkoZopDvWhreHFARQadFqIyAiKToxyXWllxzdCUBKNGrU"
                "IjLImqAwragDwWawUzHHyhKbDOnTuENEpandTpzkSipoeqKYrUGrbSsgGFBCMp"
                "hDRWHKlIwdQMTVEgvxaDODwJlEQNhCEQIvMpgzzefqQANWGKtGoiL"));
}
