#ifndef SANDBOX_FOR_JACOB_8GD_PROJECT_FORMAT_DESCRIPTIONS_H
#define SANDBOX_FOR_JACOB_8GD_PROJECT_FORMAT_DESCRIPTIONS_H
#include <string>
#include <map>
#include <vector>



struct SequenceFileFormatDescript {
    // ---- название ----
    // уникальное имя формата для работы ПО
    std::string formatName;
    // названние формата для чтения человеком, напрример: FASTA, FASTAQ
    std::string formatGeneralName;
    // название варианта формата для чтения человеком, например: FASTA {general, nsbi, naked, genbank}
    std::string formatVariantName;
    // ---- основные свойства ----
    // содежание файла для выбора классов-обработчиков - всегда "seq"
    std::string generalType = "seq";
    // присутствуют сведения о качестве:  "always", "sometimes", "never"
    std::string qualityData = "never";
    // последователльность может быть записана в несколько строк, варианты: "always", "sometimes", "never"
    std::string multylineSequence  = "never";
    // в файле может содержаться несколько последовательносей, варианты: "alwaysOne", "alwaysTwo", "sometimesMany"
    std::string multyitem = "never";
    // паттерн для первой строки для определения типа файла
    std::string fileTypePatternInFirstLine;
    // возможность парсинга заголовка:
    // "never" - отсутствует,
    // "sometimes" - возможна, но не является необходимой
    // "always" - без парсинга заголовка дальнешее чтение невозможно
    std::string headerShouldBeParsed = "never";
    // многострочный заголовок
    std::string multylineHeader = "never";
    // ---- типы строк ----
    // строка заголовка, значенния: "always", "sometimes", "never"
    std::string headerLine = "never";
    // строка комментария, значенния: "always", "sometimes", "never"
    std::string commentLine = "never";
    // строка заголовка для качества, значенния: "always", "sometimes", "never"
    std::string qualityHeaderLine = "never";
    // разделительная линия между последовательностями, значенния: "always", "sometimes", "never"
    std::string itemsDevideLine = "never";
    // многострочный заголовок
    std::string multilineHeaderLines = "never";
    // последнняя строка многострочного заголовка
    std::string lastHeaderLine = "never";
    // строка следующая за окончанием последовательности
    std::string sequenceTerminalLine = "never";
    // последовательность строк
    std::vector<std::string> lineOrder;
    // ---- список управляющих символов ----
    // обозначение начала заголовка последовательности, значенния: "always", "sometimes", "never"
    std::string headerLineStart = "never";
    // обозначение начала комментария, значенния: "always", "sometimes", "never"
    std::string commentLineStart = "never";
    // наичие рсимвола-разделителя для парсинга заголовка
    std::string headerItemsDevider = "never";
    // обозначение окончания последовательности, значенния: "always", "sometimes", "never"
    std::string sequenceTerminal = "never";
    // обозначение начала заголовка качества, значенния: "always", "sometimes", "never"
    std::string qualityLineHeaderStart = "never";
    // ---- управляющие символы ----
    // символ для обозначения начала заголовка
    std::string headerLineStartSymbol;
    // символ для обозначения начала комментария
    std::string commentLineStartSymbol;
    // символ-разделитель для парсинга заголовка
    std::string headerItemsDeviderSymbol;
    // символ для обозначения начала заголовка качества
    std::string qualityLineHeaderStartSymbol;
    // символ для обозначения окончания последовательности
    std::string sequenceTerminalSymbol;
    // строка заголовка перед начаом последовательности
    std::string lastHeaderLineText;
    // строка, следующая после окончания последовательности (завершение)
    std::string sequenceTerminalLineText;
    // ---- форматирование последовательностей ----
    // ширина строки данных фиксирована
    std::string fixedLineWidth = "never";
    // ширина строки
    int lineWide = 80;
    // последовательность разбита на столбцы с пробелом-разделителем
    std::string sequenceColumns = "never";
    // ширина столбца, на который разбита последовательность
    int datalineColumnWide;
    // cчётчик симмволов в строке последовательности: "always", "sometimes", "never"
    std::string sequenceRowCharCount = "newer";
    // положение счётчтка символов относительно данных: "left", "right" (left - GenBank, right - EMBI)
    std::string sequenceRowCharCountPosition;
    // ---- оценки качества ----
    // метод оценки, значения: "psanger", "solexaPreV.1.3"
    std::string qualityScoreMetod;
    // диапазон значений оценки качесвтва
    std::vector <int> qualityScoreRange = {0,0};
    // диапазон значений кодов ASCII для оценки качества
    std::vector <int> qualityScoreIncoding = {0,0};
    // информация о файле-источнике
    // расширение файла
    std::vector<std::string> fileExtention;
    SequenceFileFormatDescript () = default;
};

class AllSequencesFileFormatDescription {
public:
    std::map<std::string, SequenceFileFormatDescript> dlst;
    AllSequencesFileFormatDescription() = default;
    void init();
    std::vector <std::string> getAllNormalFastaFormatNames();
    std::vector <std::string> getAllNormalFastaqFormatNames();
};

struct PairAlignmentFileFormatDescript{
    // ---- название ----
    // уникальное имя формата для работы ПО
    std::string formatName;
    // названние формата для чтения человеком, напрример: FASTA, FASTAQ
    std::string formatGeneralName;
    // название варианта формата для чтения человеком, например: FASTA {general, nsbi, naked, genbank}
    std::string formatVariantName;
    // ---- основные свойства ----
    // содежание файла для выбора классов-обработчиков - всегда "pair"
    std::string generalType = "pair";
    // присутствуют сведения о качестве:  "always", "sometimes", "never"
    std::string qualityData = "never";
    // последователльность может быть записана в несколько строк, варианты: "always", "sometimes", "never"
    std::string multylineSequence  = "never";
    // паттерн для первой строки для определения типа файла
    std::string fileTypePatternInFirstLine;

    // ---- типы строк заголовка----
    // многострочный заголовок (более 2 строк)
    std::string multylineHeader = "never";
    // первая строка заголовка, значенния: "always", "sometimes", "never"
    std::string commonHeaderFirstLine = "never";
    // вторая строка заголовка, значенния: "always", "sometimes", "never"
    std::string commonHeaderSecondLine = "never";
    // ---- типы строк данных ---
    // отдельная строка с именем последовательности: "always", "sometimes", "never"
    std::string sequenceNameLine = "never";
    // строка заголовка для качества, значенния: "always", "sometimes", "never"
    std::string sequenceNameInSequenceLine = "never";
    // пустая строка резделитель между заголовком и данными
    std::string headerAndSequenceDevideLine = "never";
    // пустая строка  между последовательностями, значенния: "always", "sometimes", "never"
    std::string sequenceDevideLine = "never";

    // последнняя строка многострочного заголовка
    std::string lastHeaderLine = "never";
    // строка следующая за окончанием последовательности
    std::string sequenceTerminalLine = "never";
    // последовательность строк
    std::vector<std::string> lineOrder;
    // ---- список управляющих символов ----
    // обозначение начала заголовка последовательности, значенния: "always", "sometimes", "never"
    std::string headerLineStart = "never";
    // обозначение начала строки с именем последовательности: "always", "sometimes", "never"
    std::string sequenceNameLineStart = "never";
    // наичие рсимвола-разделителя для парсинга заголовка
//    std::string headerItemsDevider = "never";
    // обозначение окончания последовательности, значенния: "always", "sometimes", "never"
//    std::string sequenceTerminal = "never";
    // обозначение начала заголовка качества, значенния: "always", "sometimes", "never"
//    std::string qualityLineHeaderStart = "never";
    // ---- управляющие символы ----
    // символ для обозначения начала заголовка
    std::string headerLineStartSymbol;
    // символ для обозначения начала строки с именем последовательности
    std::string sequenceNameLineStartSymbol;
    // символ для разделения имени последовательности и собственно данных в одной строке
    std::string sequenceNameAndDataDevider;
    // символ-разделитель для парсинга заголовка
//    std::string headerItemsDeviderSymbol;
    // символ для обозначения начала заголовка качества
//    std::string qualityLineHeaderStartSymbol;
    // символ для обозначения окончания последовательности
//    std::string sequenceTerminalSymbol;
    // строка заголовка перед начаом последовательности
//    std::string lastHeaderLineText;
    // строка, следующая после окончания последовательности (завершение)
//    std::string sequenceTerminalLineText;
    // ---- форматирование последовательностей ----
    // символ для обозначнеия разрыва
    std::string gapSymbol = "-";
    // ширина строки данных фиксирована
    std::string fixedLineWidth = "never";
    // ширина строки
    int lineWide = 80;
    // последовательность разбита на столбцы с пробелом-разделителем
    std::string sequenceColumns = "never";
    // ширина столбца, на который разбита последовательность
    int datalineColumnWide;
    // cчётчик симмволов в строке последовательности: "always", "sometimes", "never"
    std::string sequenceRowCharCount = "newer";
    // положение счётчтка символов относительно данных: "left", "right" (left - GenBank, right - EMBI)
    std::string sequenceRowCharCountPosition;
    // ---- оценки качества ----
    // метод оценки, значения: "psanger", "solexaPreV.1.3"
    std::string qualityScoreMetod;
    // диапазон значений оценки качесвтва
//    std::vector <int> qualityScoreRange = {0,0};
    // диапазон значений кодов ASCII для оценки качества
//    std::vector <int> qualityScoreIncoding = {0,0};
    // информация о файле-источнике
    // расширение файла
    std::vector<std::string> fileExtention;
    PairAlignmentFileFormatDescript() = default;
};

class AllPairAlignmentFileFormatDescription {
public:
    std::map<std::string, PairAlignmentFileFormatDescript> dlst;
    AllPairAlignmentFileFormatDescription() = default;
    void init();
};

struct MultypleAlignmentFileFormatDescript {
    // ---- название ----
    // уникальное имя формата для работы ПО
    std::string formatName;
    // названние формата для чтения человеком, напрример: FASTA, FASTAQ
    std::string formatGeneralName;
    // название варианта формата для чтения человеком, например: FASTA {general, nsbi, naked, genbank}
    std::string formatVariantName;
    // ---- основные свойства ----
    // содежание файла для выбора классов-обработчиков - всегда "msa"
    std::string generalType = "msa";
    // присутствуют сведения о качестве:  "always", "sometimes", "never"
    std::string qualityData = "never";
    // последователльность может быть записана в несколько строк, варианты: "always", "sometimes", "never"
    std::string multylineSequence = "never";
    // паттерн для первой строки для определения типа файла
    std::string fileTypePatternInFirstLine;
    // ---- типы строк заголовка----
    // первая строка заголовка, значенния: "always", "sometimes", "never"
    std::string commonHeaderFirstLine = "never";
    // последовательность строк
    std::vector<std::string> lineOrder;
    // ---- список управляющих символов ----
    // обозначение начала заголовка последовательности, значенния: "always", "sometimes", "never"
    std::string headerLineStart = "never";
    // обозначение начала строки с именем последовательности: "always", "sometimes", "never"
    std::string sequenceNameLineStart = "never";


    MultypleAlignmentFileFormatDescript() = default;
};

class AllMultypleAlignmentFileFormatDescription {
public:
    std::map<std::string, MultypleAlignmentFileFormatDescript> dlst;
    AllMultypleAlignmentFileFormatDescription() = default;
    void init();
};


#endif //SANDBOX_FOR_JACOB_8GD_PROJECT_FORMAT_DESCRIPTIONS_H
