#include "sequences_files_format_descriptions.h"

void AllSequencesFileFormatDescription::init() {
    // ---- FASTA общее описание ----
    // general
    SequenceFileFormatDescript fasta_gen;
    // название формата
    fasta_gen.format_main_name = "FASTA";
    fasta_gen.format_variant_name = "geenral";
    // основные свойства
    fasta_gen.quality_data = "never";
    fasta_gen.multyline_sequence = "sometimes";
    fasta_gen.multyitem = "sometimes";
    // типы строк
    fasta_gen.header_line = "always";
    fasta_gen.comment_line = "sometimes";
    fasta_gen.devide_line = "sometimes";
    fasta_gen.line_order = {"header", "comment", "sequence", "devide"};
    // список управляющих символов
    fasta_gen.header_line_start = "always";
    fasta_gen.comment_line_start  = "sometimes";
    fasta_gen.sequence_terminal = "sometimes";
    // управляющие символы
    fasta_gen.header_line_start_symbol = ">";
    fasta_gen.comment_line_start_symbol = ";";
    fasta_gen.sequence_terminal_symbol = "*";
    // форматирование последовательностей
    fasta_gen.fixed_line_width = "sometimes";
    // информация о файле-источнике
    fasta_gen.file_extention = {"fasta", "fa", "fna", "ffn", "faa", "frn", "txt"};
    dlst["FASTA_general"] = fasta_gen;
    // ---- FASTA без заголовка ----
    SequenceFileFormatDescript fasta_bare = fasta_gen;
    // название формата
    fasta_bare.format_variant_name = "bare";
    // основные свойства
    fasta_bare.multyline_sequence = "sometimes";
    fasta_bare.multyitem = "never";
    // типы строк
    fasta_bare.line_order = {"sequence"};
    // список управляющих символов
    // управляющие символы
    // форматирование последовательностей
    fasta_bare.fixed_line_width = "sometimes";
    dlst["FASTA_bare"] = fasta_bare;
    // ---- NCBI Fasta db link----
    // файлы с заголовком вида: >идентификатор базы данных|код в базе данных|название
    // например: >gi|186704|Keratin Homo sapiens
    SequenceFileFormatDescript fasta_NCBI_db_link = fasta_gen;
    fasta_NCBI_db_link.format_variant_name = "NCBI_db_link";
    fasta_NCBI_db_link.header_items_devider = "sometimes";
    fasta_NCBI_db_link.header_items_devider_symbol = "|";
    dlst["FASTA_NCBI_db_link"] = fasta_NCBI_db_link;
    // ---- NCBI Fasta ----
    // файлы с заголовком вида: >код_в_базе_данных_NCBI.версия Название
    // например: >BX284601.5 Caenorhabditis elegans chromosome
    SequenceFileFormatDescript fasta_NCBI_common = fasta_gen;
    fasta_NCBI_common.format_variant_name = "NCBI_common";
    fasta_NCBI_common.header_items_devider = "sometimes";
    fasta_NCBI_common.header_items_devider_symbol = " ";
    dlst["FASTA_NCBI_common"] = fasta_NCBI_common;
    // ---- GenBank Fasta ----
    // очень спеифичный формат с многострочным заголовком
    SequenceFileFormatDescript fasta_GenBank;
    fasta_GenBank.format_main_name = "FASTA";
    fasta_GenBank.format_variant_name = "NCBI_GenBank";
    fasta_GenBank.multyline_sequence = "always";
    fasta_GenBank.header_should_be_parsed = "sometimes";
    fasta_GenBank.multyline_header = "always";
    fasta_GenBank.multiline_header_lines = "always";
    fasta_GenBank.last_header_line  = "always";
    fasta_GenBank.sequence_terminal_line = "never";
    fasta_GenBank.line_order = fasta_gen.line_order = {"multiline_header", "last_header_line", "sequence", "terminal_line"};
    fasta_GenBank.header_line_start = "never";
    fasta_GenBank.comment_line_start = "never";
    fasta_GenBank.last_header_line_text = "ORIGIN";
    fasta_GenBank.sequence_terminal_line_text = "//";
    fasta_GenBank.fixed_line_width = "always";
    fasta_GenBank.sequence_columns = "always";
    fasta_GenBank.dataline_column_wide = 10;
    fasta_GenBank.dataline_rowstart_number = "always";
    fasta_GenBank.file_extention = {"fasta", "fa", "fna", "ffn", "faa", "frn", "txt"};
    dlst["FASTA_GenBank"] = fasta_GenBank;
    // ---- FASTAQ ----
    // FASTAQ - форматы с информацией о достоверности данных
    // базовый вариант: sanger
    SequenceFileFormatDescript fastaq_sanger;
    //
    fastaq_sanger.format_main_name = "FASTAQ";
    fastaq_sanger.format_variant_name = "sanger";
    //
    fastaq_sanger.quality_data = "always";
    fastaq_sanger.multyline_sequence = "sometimes";
    fastaq_sanger.multyitem = "sometimes";
    //
    fastaq_sanger.header_line = "always";
    fastaq_sanger.quality_header_line = "always";
    fastaq_sanger.devide_line = "sometimes";
    fastaq_sanger.line_order = {"header", "sequence", "quality_header", "quality_sequence" "devide"};
    //
    fastaq_sanger.header_line_start = "always";
    fastaq_sanger.quality_line_header_start = "always";
    //
    fastaq_sanger.header_line_start_symbol = "@";
    fastaq_sanger.quality_line_header_start_symbol = "+";
    //
    fastaq_sanger.fixed_line_width = "sometimes";
    //
    fastaq_sanger.quality_score_metod = "sanger";
    fastaq_sanger.quality_score_range = {0, 93};
    fastaq_sanger.quality_score_incoding = {33, 126};
    //
    fastaq_sanger.file_extention = {"fastaq", "fq"};
    dlst["FASTAQ_sanger"] = fastaq_sanger;
    // ---- FASTAQ solexa ----
    SequenceFileFormatDescript fastaq_solexa = fastaq_sanger;
    //
    fastaq_solexa.quality_score_metod = "solexa";
    fastaq_solexa.quality_score_range = {-5, 62};
    fastaq_solexa.quality_score_incoding = {59, 126};
    dlst["FASTAQ_solexa"] = fastaq_solexa;
    // ---- FASTAQ Illumina ----
    // Illumina v1.0
    SequenceFileFormatDescript fastaq_illumina_v1_0 = fastaq_solexa;
    dlst["FASTAQ_illumina_v_1_0"] = fastaq_illumina_v1_0;
    // Illumina v1.3
    SequenceFileFormatDescript fastaq_illumina_v1_3 = fastaq_sanger;
    fastaq_illumina_v1_3.quality_score_range = {0, 62};
    fastaq_illumina_v1_3.quality_score_incoding = {64, 126};
    dlst["FASTAQ_illumina_v_1_3"] = fastaq_illumina_v1_3;
    // Illumina v1.5
    SequenceFileFormatDescript fastaq_illumina_v1_5 = fastaq_illumina_v1_3;
    fastaq_illumina_v1_5.quality_score_range = {3, 62};
    fastaq_illumina_v1_5.quality_score_incoding = {67, 126};
    dlst["FASTAQ_illumina_v_1_5"] = fastaq_illumina_v1_5;
    // Illumina v1.8
    SequenceFileFormatDescript fastaq_illumina_v1_8 = fastaq_sanger;
    dlst["FASTAQ_illumina_v_1_8"] = fastaq_illumina_v1_8;
}

std::vector <std::string> AllSequencesFileFormatDescription::getAllNormalFastaFormatNames() {
    std::vector<std::string> result;
    for (const auto & item : dlst){
//        printf("%s\n", item.first.c_str());
        if (item.second.quality_data == "never" &&
            item.second.header_line_start == "always" &&
            item.second.header_line_start_symbol == ">" ){
            result.push_back(item.first);
        }
    }
    return result;
}

std::vector <std::string> AllSequencesFileFormatDescription::getAllNormalFastaqFormatNames() {
    std::vector<std::string> result;
    for (const auto & item : dlst){
//        printf("%s\n", item.first.c_str());
        if (item.second.quality_data == "always" &&
            item.second.header_line_start == "always" &&
            item.second.header_line_start_symbol == "@" ){
            result.push_back(item.first);
        }
    }
    return result;
}