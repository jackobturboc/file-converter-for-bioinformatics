#ifndef SANDBOX_FOR_JACOB_8GD_PROJECT_SEQUENCES_FILES_FORMAT_DESCRIPTIONS_H
#define SANDBOX_FOR_JACOB_8GD_PROJECT_SEQUENCES_FILES_FORMAT_DESCRIPTIONS_H
#include <string>
#include <map>
#include <vector>



struct SequenceFileFormatDescript {
    // ---- название ----
    // названние формата, напрример: FASTA, FASTAQ
    std::string format_main_name;
    // название варианта формата, например: FASTA {general, nsbi, naked, genbank}
    std::string format_variant_name;
    // ---- основные свойства ----
    // присутствуют сведения о качестве:  "always", "sometimes", "never"
    std::string quality_data = "never";
    // последователльность может быть записана в несколько строк, варианты: "always", "sometimes", "never"
    std::string multyline_sequence  = "never";
    // в файле может содержаться несколько последовательносей, варианты: "always_one", "always_two", "sometimes_many"
    std::string multyitem = "never";
    // возможность парсинга заголовка:
    // "never" - отсутствует,
    // "sometimes" - возможна, но не является необходимой
    // "always" - без парсинга заголовка дальнешее чтение невозможно
    std::string header_should_be_parsed = "never";
    // многострочный заголовок
    std::string multyline_header = "never";
    // ---- типы строк ----
    // строка заголовка, значенния: "always", "sometimes", "never"
    std::string header_line = "never";
    // строка комментария, значенния: "always", "sometimes", "never"
    std::string comment_line = "never";
    // строка заголовка для качества, значенния: "always", "sometimes", "never"
    std::string quality_header_line = "never";
    // разделительная линия между последовательностями, значенния: "always", "sometimes", "never"
    std::string devide_line = "never";
    // многострочный заголовок
    std::string multiline_header_lines = "never";
    // последнняя строка многострочного заголовка
    std::string last_header_line = "never";
    // строка следующая за окончанием последовательности
    std::string sequence_terminal_line = "never";
    // последовательность строк
    std::vector<std::string> line_order;
    // ---- список управляющих символов ----
    // обозначение начала заголовка последовательности, значенния: "always", "sometimes", "never"
    std::string header_line_start = "never";
    // обозначение начала комментария, значенния: "always", "sometimes", "never"
    std::string comment_line_start = "never";
    // наичие рсимвола-разделителя для парсинга заголовка
    std::string header_items_devider = "never";
    // обозначение окончания последовательности, значенния: "always", "sometimes", "never"
    std::string sequence_terminal = "never";
    // обозначение начала заголовка качества, значенния: "always", "sometimes", "never"
    std::string quality_line_header_start = "never";
    // ---- управляющие символы ----
    // символ для обозначения начала заголовка
    std::string header_line_start_symbol;
    // символ для обозначения начала комментария
    std::string comment_line_start_symbol;
    // символ-разделитель для парсинга заголовка
    std::string header_items_devider_symbol;
    // символ для обозначения начала заголовка качества
    std::string quality_line_header_start_symbol;
    // символ для обозначения окончания последовательности
    std::string sequence_terminal_symbol;
    // строка заголовка перед начаом последовательности
    std::string last_header_line_text;
    // строка, следующая после окончания последовательности (завершение)
    std::string sequence_terminal_line_text;
    // ---- форматирование последовательностей ----
    // ширина строки данных фиксирована
    std::string fixed_line_width = "never";
    // последовательность разбита на столбцы с пробелом-разделителем
    std::string sequence_columns = "never";
    // ширина столбца, на который разбита последовательность
    int dataline_column_wide;
    // номер элемента последовательности в начале строки
    std::string dataline_rowstart_number = "never";
    // ---- оценки качества ----
    // метод оценки, значения: "psanger", "solexa_pre_v.1.3"
    std::string quality_score_metod;
    // диапазон значений оценки качесвтва
    std::vector <int> quality_score_range = {0,0};
    // диапазон значений кодов ASCII для оценки качества
    std::vector <int> quality_score_incoding = {0,0};
    // информация о файле-источнике
    // расширение файла
    std::vector<std::string> file_extention;
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

struct AlignmentFileFormatDescript{
    // ---- название ----
    // названние формата, напрример: FASTA+GAP, CLUSTAL W, PHYLIP, NEXUS
    std::string format_main_name;
    // название варианта формата, например: ...
    std::string format_variant_name;
    // ---- основные свойства ----
    // тип выравнивания по числу последовательностей: парное "pair_wise", множественное "multiple"
    std::string alignment_type = "multiple";
    // последователльность может быть записана в несколько строк, варианты: "always", "sometimes", "never"
    std::string multyline_sequence  = "never";
    // в файле может содержаться несколько последовательносей, варианты: "always_one", "always_two", "sometimes_many"
    std::string multyitem = "never";
    // присутствуют сведения о качестве:
    std::string quality_data = "never";
    AlignmentFileFormatDescript() = default;
};

#endif //SANDBOX_FOR_JACOB_8GD_PROJECT_SEQUENCES_FILES_FORMAT_DESCRIPTIONS_H
