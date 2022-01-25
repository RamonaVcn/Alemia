## Scop Alemia

Alemia este un proiect ce are ca obiect preluarea proiectelor si fisierelor
de la studenti in care au codat cerinta si pe baza unor date anterioare sa poata 
sa prezica nota  

## Modalitate de indeplinere

Pentru a realiza aceasta prezicere Alemia creeaza niste criterii relevante pe
baza carora sa determina nota, iar aceste criterii se pot regasi si ca denumirile 
coloanelor din features.csv (numarul de functii, de headere, de erori etc)
iar aceste elemente sunt in modul features_extraction prin folosirea regex-urilor 
pe baza unor cuvinte cheie 
````
        inheritance_pattern = re.compile(r"([A-Z])\w+ : ([a-z]\w+)")
        virtual_pattern = re.compile(r"virtual ([a-z]\w+)")
        static_pattern = re.compile(r"\W*(static)\W*")
        global_pattern = re.compile(r"\W*(global)\W*")
        public_pattern = re.compile(r"\W*(public)\W*")
        private_pattern = re.compile(r"\W*(private)\W*")
        protected_pattern = re.compile(r"\W*(protected)\W*")
        define_pattern = re.compile(r"^#define*")
        template_pattern = re.compile(r"\W*(template)\W*")
        stl_pattern = re.compile(r"\W*(std)\W*")
        namespace_pattern = re.compile(r"\W*(namespace)\W*")
        comments_pattern = re.compile(r"\W*(/\*)|(//)\W*")
        enum_pattern = re.compile(r"\W*(enum)\W*")
        struct_pattern = re.compile(r"W*(stuct)\W*")
        function_pattern = re.compile(r"\W*(\(\))\W*")
````
Cum ar fi struct, enum, public deci elemente de sintaxa C++

## Alte tipuri de inputuri

Cum aceste regex-uri cauta elemente de sintaxa potrivita pentru C++, alte proiecte
scrise in C, Python, C# etc nu ar duce la o prezicere de nota asa buna deoarce intr-adevar la fiecare limbaj anumite elemente sunt la fel dar nu in totalitate
astfel nu ar numara toate criteriile necesare pentru acel proiect scris in alt limbaj
pentru a oferi o nota.

## Concluzie

Datorita unor asemenari dintre limbajele de programare, Alemia ar putea prezice nota pentru orice proiect scris in orice limbaj doar ca nu ar oferi o acuratete asa buna pentru nota decat pentru Limbajul C++. Pentru a fi potrivit si alte limbaje este necesara implementarea unor module ce determina tipul de limbaj de programare folosit,
iar pentru fiecare realizat un modul cu regex-urile potrivite, desigur in prima faza pentru cele mai populare cum ar fi Java,C#, Python sau Javascript

