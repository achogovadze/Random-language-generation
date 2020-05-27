In the past few decades, computers have revolutionized student life. In addition to providing no end of
entertainment and distractions, computers also have also facilitated much productive student work.
However, one important area of student labor that has been painfully neglected is the task of filling up
space in papers, Ph.D. dissertations, grant proposals, and recommendation letters with important
sounding and somewhat sensible random sequences. Come on, you know the overworked
TA/professor/reviewer doesn’t have time to read too closely. . . .
To address this burning need, the random writer is designed to produce somewhat sensible output by
generalizing from patterns found in the input text. When you’re coming up short on that 10-page paper
due tomorrow, feed in the eight pages you already have written into the random writer, and—Voila!—
another couple of pages appear. You can even feed your own .cpp files back into your program and
have it build a new random program on demand.
How does random writing work?
Random writing is based on an idea advanced by Claude Shannon in 1948 and subsequently
popularized by A. K. Dewdney in his Scientific American column in 1989. Shannon’s famous paper
introduces the idea of a Markov model for English text. A Markov model is a statistical model that
describes the future state of a system based on the current state and the conditional probabilities of the
possible transitions. Markov models have a wide variety of uses, including recognition systems for
handwriting and speech, machine learning, and bioinformatics. Even Google’s PageRank algorithm
has a Markov component to it. In the case of English text, the Markov model is used to describe the
possibility of a particular character appearing given the sequence of characters seen so far. The
sequence of characters within a body of text is clearly not just a random rearrangement of letters, and
the Markov model provides a way to discover the underlying patterns and, in this case, to use those
patterns to generate new text that fits the model.
