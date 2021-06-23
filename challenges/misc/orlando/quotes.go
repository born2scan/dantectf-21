package main

import (
	"math/rand"
	"time"
)

var (
	seeded = false
	quotes = [][]string{
		{"Ed ecco, quasi al cominciar de l'erta,\nuna ________ ________ e presta molto,\nche di pel macolato era coverta;", "lonza leggiera"},
		{"Virgilio, quando prender si sentio,\ndisse a me: \"Fatti qua, si' ch'io ti prenda\";\npoi fece si' ch'un fascio era ________ e io.", "elli"},
		{"Su' mi levai, e tutti eran gia' pieni\nde l'alto di' i ________ del sacro monte,\ne andavam col sol novo a le reni.", "giron"},
		{"Poi comincio': \"Nel beato concilio\nti ponga in pace la verace corte\nche me rilega ne l'_______ essilio\".", "etterno"},
		{"Gia' era l'angel dietro a noi rimaso,\nl'angel che n'avea volti al ________ ________,\navendomi dal viso un colpo raso;", "sesto giro"},
		{"Sanza restarsi, per sé stessa cade\n________ a l'una de le rive;\nquivi conosce prima le sue strade.", "mirabilmente"},
	}
)

func GetQuotes() [][]string {
	if !seeded {
		rand.Seed(time.Now().Unix())
		seeded = true
	}

	startIndex := rand.Intn(len(quotes) - 2)
	return quotes[startIndex : startIndex+3]
}
