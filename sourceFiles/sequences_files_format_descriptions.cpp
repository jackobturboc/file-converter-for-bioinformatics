#include "sequences_files_format_descriptions.h"

void AllSequencesFileFormatDescription::init() {
    // ---- FASTA общее описание ----
    // general
    SequenceFileFormatDescript fasta_gen;
    // название формата
    fasta_gen.formatName = "FASTA_general";
    fasta_gen.formatGeneralName = "FASTA";
    fasta_gen.formatVariantName = "geenral";
    // основные свойства
    fasta_gen.qualityData = "never";
    fasta_gen.multylineSequence = "sometimes";
    fasta_gen.multyitem = "sometimes";
    // прризнаки формата в файле
    fasta_gen.fileTypePatternInFirstLine = ">";
    // типы строк
    fasta_gen.headerLine = "always";
    fasta_gen.commentLine = "sometimes";
    fasta_gen.itemsDevideLine = "sometimes";
    fasta_gen.lineOrder = {"header", "comment", "sequence", "devide"};
    // список управляющих символов
    fasta_gen.headerLineStart = "always";
    fasta_gen.commentLineStart  = "sometimes";
    fasta_gen.sequenceTerminal = "sometimes";
    // управляющие символы
    fasta_gen.headerLineStartSymbol = ">";
    fasta_gen.commentLineStartSymbol = ";";
    fasta_gen.sequenceTerminalSymbol = "*";
    // форматирование последовательностей
    fasta_gen.fixedLineWidth = "sometimes";
    // информация о файле-источнике
    fasta_gen.fileExtention = {"fasta", "fa", "fna", "ffn", "faa", "frn", "txt"};
    dlst[fasta_gen.formatName] = fasta_gen;
    // ---- FASTA без заголовка ----
    SequenceFileFormatDescript fasta_bare = fasta_gen;
    // название формата
    fasta_bare.formatName = "FASTA_bare";
    fasta_bare.formatVariantName = "bare";
    // основные свойства
    fasta_bare.multylineSequence = "sometimes";
    fasta_bare.multyitem = "never";
    // типы строк
    fasta_bare.lineOrder = {"sequence"};
    // список управляющих символов
    // управляющие символы
    // форматирование последовательностей
    fasta_bare.fixedLineWidth = "sometimes";
    dlst[fasta_bare.formatName] = fasta_bare;
    // ---- NCBI Fasta db link----
    // файлы с заголовком вида: >идентификатор базы данных|код в базе данных|название
    // например: >gi|186704|Keratin Homo sapiens
    SequenceFileFormatDescript fasta_NCBI_db_link = fasta_gen;
    fasta_NCBI_db_link.formatName = "FASTA_NCBI_db_link";
    fasta_NCBI_db_link.formatVariantName = "NCBI_db_link";
    fasta_NCBI_db_link.fileTypePatternInFirstLine = ">.{2,3}\\|";
    fasta_NCBI_db_link.headerItemsDevider = "sometimes";
    fasta_NCBI_db_link.headerItemsDeviderSymbol = "|";
    dlst[fasta_NCBI_db_link.formatName] = fasta_NCBI_db_link;
    // ---- NCBI Fasta ----
    // файлы с заголовком вида: >код_в_базе_данных_NCBI.версия Название
    // например: >BX284601.5 Caenorhabditis elegans chromosome
    SequenceFileFormatDescript fasta_NCBI_common = fasta_gen;
    // прризнаки формата в файле
    fasta_NCBI_common.formatName = "FASTA_NCBI_common";
    fasta_NCBI_common.formatVariantName = "NCBI_common";
    fasta_NCBI_common.fileTypePatternInFirstLine = ">[A-Z]{2,3}_?\\d{2,}\\.?\\d{1,2}";
    fasta_NCBI_common.headerItemsDevider = "sometimes";
    fasta_NCBI_common.headerItemsDeviderSymbol = " ";
    dlst[fasta_NCBI_common.formatName] = fasta_NCBI_common;
    // ---- GenBank Fasta ----
    // очень спеифичный формат с многострочным заголовком
    SequenceFileFormatDescript GenBank;
    GenBank.formatName = "NCBI_GenBank";
    GenBank.formatGeneralName = "FASTA";
    GenBank.formatVariantName = "NCBI_GenBank";
    GenBank.multylineSequence = "always";
    GenBank.fileTypePatternInFirstLine = "LOCUS";
    GenBank.headerShouldBeParsed = "sometimes";
    GenBank.multylineHeader = "always";
    GenBank.multilineHeaderLines = "always";
    GenBank.lastHeaderLine  = "always";
    GenBank.sequenceTerminalLine = "always";
    GenBank.lineOrder = fasta_gen.lineOrder = {"multiline_header", "last_header_line", "sequence", "terminal_line"};
    GenBank.headerLineStart = "never";
    GenBank.commentLineStart = "never";
    GenBank.lastHeaderLineText = "ORIGIN";
    GenBank.sequenceTerminalLineText = "//";
    GenBank.fixedLineWidth = "always";
    GenBank.sequenceColumns = "always";
    GenBank.datalineColumnWide = 10;
    GenBank.sequenceRowCharCount = "always";
    GenBank.sequenceRowCharCountPosition = "left";
    GenBank.fileExtention = {"gb", "txt"};
    dlst[GenBank.formatName] = GenBank;

    SequenceFileFormatDescript EMBI = GenBank;
    EMBI.formatName = "EMBI";
    EMBI.formatVariantName = "EMBI";
    EMBI.fileTypePatternInFirstLine = "ID ";
    EMBI.lastHeaderLineText = "SQ ";
    EMBI.sequenceRowCharCountPosition = "right";
    EMBI.fileExtention = {"txt"};
    dlst[EMBI.formatName] = EMBI;

    // EMBI с укороченным заголовком
    SequenceFileFormatDescript GCG = EMBI;
    GCG.formatName = "GCG";
    GCG.formatVariantName = "GCG";
    GCG.fileTypePatternInFirstLine = "ID ";
    GCG.lastHeaderLineText = "(.*)Length(.*)Check(.*)";
    GCG.sequenceRowCharCountPosition = "left";
    GCG.fileExtention = {"txt"};
    dlst[GCG.formatName] = GCG;

    SequenceFileFormatDescript PIR;
    PIR.formatName = "PIR";
    dlst[PIR.formatName] = PIR;

    // ---- FASTAQ ----
    // FASTAQ - форматы с информацией о достоверности данных
    // обобщённый формат для всех FASTAQ - для определения и чтения: по данным однозначно определить
    // конкретную версию невозможно, но без конвертации в другие типы fastaq и не нужно
    SequenceFileFormatDescript fastaq_general;
    //
    fastaq_general.formatName = "FASTAQ_general";
    fastaq_general.formatGeneralName = "FASTAQ";
    fastaq_general.formatVariantName = "general";
    //
    fastaq_general.qualityData = "always";
    fastaq_general.multylineSequence = "sometimes";
    fastaq_general.multyitem = "sometimes";
    //
    fastaq_general.headerLine = "always";
    fastaq_general.qualityHeaderLine = "always";
    fastaq_general.itemsDevideLine = "sometimes";
    fastaq_general.lineOrder = {"header", "sequence", "quality_header", "quality_sequence" "devide"};
    //
    fastaq_general.headerLineStart = "always";
    fastaq_general.qualityLineHeaderStart = "always";
    //
    fastaq_general.headerLineStartSymbol = "@";
    fastaq_general.qualityLineHeaderStartSymbol = "+";
    //
    fastaq_general.fixedLineWidth = "sometimes";
    //
    fastaq_general.fileExtention = {"fastaq", "fq"};
    dlst[fastaq_general.formatName] = fastaq_general;

    // базовый вариант: sanger
    SequenceFileFormatDescript fastaq_sanger = fastaq_general;
    //
    fastaq_sanger.formatName = "FASTAQ_sanger";
    fastaq_sanger.formatVariantName = "sanger";
    //
    fastaq_sanger.qualityScoreMetod = "sanger";
    fastaq_sanger.qualityScoreRange = {0, 93};
    fastaq_sanger.qualityScoreIncoding = {33, 126};
    dlst[fastaq_sanger.formatName] = fastaq_sanger;

    // ---- FASTAQ solexa ----
    SequenceFileFormatDescript fastaq_solexa = fastaq_sanger;
    fastaq_solexa.formatName = "FASTAQ_solexa";
    fastaq_solexa.formatVariantName = "solexa";
    //
    fastaq_solexa.qualityScoreMetod = "solexa";
    fastaq_solexa.qualityScoreRange = {-5, 62};
    fastaq_solexa.qualityScoreIncoding = {59, 126};
    dlst["FASTAQ_solexa"] = fastaq_solexa;
    // ---- FASTAQ Illumina ----
    // Illumina v1.0
    SequenceFileFormatDescript fastaq_illumina_v1_0 = fastaq_solexa;
    fastaq_illumina_v1_0.formatName = "FASTAQ_illumina_v_1_0";
    fastaq_illumina_v1_0.formatVariantName = "illumina v.1.0";
    dlst[fastaq_illumina_v1_0.formatName] = fastaq_illumina_v1_0;
    // Illumina v1.3
    SequenceFileFormatDescript fastaq_illumina_v1_3 = fastaq_sanger;
    fastaq_illumina_v1_3.formatName = "FASTAQ_illumina_v_1_3";
    fastaq_illumina_v1_3.formatVariantName = "illumina v.1.3";
    fastaq_illumina_v1_3.qualityScoreRange = {0, 62};
    fastaq_illumina_v1_3.qualityScoreIncoding = {64, 126};
    dlst[fastaq_illumina_v1_3.formatName] = fastaq_illumina_v1_3;
    // Illumina v1.5
    SequenceFileFormatDescript fastaq_illumina_v1_5 = fastaq_illumina_v1_3;
    fastaq_illumina_v1_5.formatName = "FASTAQ_illumina_v_1_5";
    fastaq_illumina_v1_5.formatVariantName = "illumina v.1.5";
    fastaq_illumina_v1_5.qualityScoreRange = {3, 62};
    fastaq_illumina_v1_5.qualityScoreIncoding = {67, 126};
    dlst[fastaq_illumina_v1_5.formatName] = fastaq_illumina_v1_5;
    // Illumina v1.8
    SequenceFileFormatDescript fastaq_illumina_v1_8 = fastaq_sanger;
    fastaq_illumina_v1_8.formatName = "FASTAQ_illumina_v_1_8";
    fastaq_illumina_v1_8.formatVariantName = "illumina v.1.8";
    dlst["FASTAQ_illumina_v_1_8"] = fastaq_illumina_v1_8;
}

void AllPairAlignmentFileFormatDescription::init() {
    PairAlignmentFileFormatDescript fasta_pairwise;
    // ---- название ----
    fasta_pairwise.formatName = "FASTA_Pairwise";
    fasta_pairwise.formatGeneralName = "FASTA";
    fasta_pairwise.formatVariantName = "Pairwise";
    fasta_pairwise.fileTypePatternInFirstLine = ">";
    fasta_pairwise.commonHeaderFirstLine = "never";
    fasta_pairwise.sequenceNameLine = "always";
    fasta_pairwise.lineOrder = {"ft_sequence_name", "ft_sequence_data", "sd_sequence_name", "sd_sequence_data"};
    fasta_pairwise.sequenceNameLineStart = "always";
    fasta_pairwise.sequenceNameInSequenceLine = "never";
    fasta_pairwise.sequenceNameLineStartSymbol = ">";
    dlst[fasta_pairwise.formatName] = fasta_pairwise;

    PairAlignmentFileFormatDescript clustal_w;
    clustal_w.formatName = "CLUSTAL_W";
    clustal_w.formatGeneralName = "CLUSTAL";
    clustal_w.formatVariantName = "W";
    clustal_w.fileTypePatternInFirstLine = "CLUSTAL W";
    clustal_w.commonHeaderFirstLine = "always";
    clustal_w.lineOrder = {"common_header", "ft_sequence_data", "sd_sequence_data"};
    clustal_w.sequenceNameInSequenceLine = "always";
    clustal_w.sequenceNameLine = "newer";
    clustal_w.sequenceNameAndDataDevider = " ";
    dlst[clustal_w.formatName] = clustal_w;

    PairAlignmentFileFormatDescript phylip;
    phylip.formatName = "PHYLIP_Pairwise";
    phylip.formatGeneralName = "PHYLIP";
    phylip.formatVariantName = "Pairwise";
    phylip.fileTypePatternInFirstLine = "\\s*2 \\d+";
    phylip.commonHeaderFirstLine = "always";
    phylip.lineOrder = {"common_header", "ft_sequence_data", "sd_sequence_data"};
    phylip.sequenceNameInSequenceLine = "always";
    phylip.sequenceNameLine = "newer";
    phylip.sequenceNameAndDataDevider = " ";
    phylip.sequenceColumns = "sometimes";
    phylip.datalineColumnWide = 10;
    dlst[phylip.formatName] = phylip;

    PairAlignmentFileFormatDescript selex;
    selex.formatName = "SELEX_Pairwise";
    selex.formatGeneralName = "SELEX";
    selex.formatVariantName = "Pairwise";
    selex.fileTypePatternInFirstLine = "#=SQ";
    selex.commonHeaderFirstLine = "always";
    selex.commonHeaderSecondLine = "always";
    selex.lineOrder = {"common_header", "ft_sequence_data", "sd_sequence_data"};
    selex.sequenceNameInSequenceLine = "always";
    selex.sequenceNameLine = "newer";
    selex.sequenceNameAndDataDevider = " ";
    dlst[selex.formatName] = selex;

    PairAlignmentFileFormatDescript nexus_pair;
    nexus_pair.formatName = "NEXUS_Pairwise";
    nexus_pair.formatGeneralName = "NEXUS";
    nexus_pair.formatVariantName = "Pairwise";
    nexus_pair.fileTypePatternInFirstLine = "#NEXUS";
    dlst[nexus_pair.formatName] = nexus_pair;

    PairAlignmentFileFormatDescript msf_pair;
    msf_pair.formatName = "MSF_Pairwise";
    msf_pair.formatGeneralName = "MSF";
    msf_pair.formatVariantName = "Pairwise";
    msf_pair.fileTypePatternInFirstLine = "!!NA_MULTIPLE_ALIGNMENT";
    dlst[msf_pair.formatName] = msf_pair;

    PairAlignmentFileFormatDescript pair;
    // здесь пока пусто
    pair.formatName = "PAIR";
    dlst[pair.formatName] = pair;

    PairAlignmentFileFormatDescript markx1;
    // здесь пока пусто
    markx1.formatName = "MARKX1";
    markx1.formatGeneralName = "MARKX";
    markx1.formatVariantName = "1";
    dlst[markx1.formatName] = markx1;

    PairAlignmentFileFormatDescript markx2 = markx1;
    // здесь пока пусто
    markx2.formatName = "MARKX2";
    markx2.formatVariantName = "2";
    dlst[markx2.formatName] = markx2;

    PairAlignmentFileFormatDescript markx3 = markx1;
    // здесь пока пусто
    markx3.formatName = "MARKX3";
    markx3.formatVariantName = "3";
    dlst[markx3.formatName] = markx3;

    PairAlignmentFileFormatDescript markx10 = markx1;
    // здесь пока пусто
    markx10.formatName = "MARKX10";
    markx10.formatVariantName = "10";
    dlst[markx10.formatName] = markx10;

    PairAlignmentFileFormatDescript srspair;
    // здесь пока пусто
    srspair.formatName = "SRSPAIR";
    srspair.formatGeneralName = "SRSPAIR";
    srspair.formatVariantName = "";
    dlst[srspair.formatName] = srspair;

    PairAlignmentFileFormatDescript blast_pair;
    blast_pair.formatName = "BLAST_Pairwise";
    blast_pair.formatGeneralName = "BLAST";
    blast_pair.formatVariantName = "Pairwise";
    blast_pair.fileTypePatternInFirstLine = "Query:";
    dlst[blast_pair.formatName] = blast_pair;
}

void AllMultypleAlignmentFileFormatDescription::init() {
    MultypleAlignmentFileFormatDescript msf_msa;
    msf_msa.formatName = "MSF_msa";
    msf_msa.formatGeneralName = "MSF";
    msf_msa.formatVariantName = "msa";
    msf_msa.fileTypePatternInFirstLine = "!!NA_MULTIPLE_ALIGNMENT";
    dlst[msf_msa.formatName] = msf_msa;

    MultypleAlignmentFileFormatDescript phylip_msa;
    phylip_msa.formatName = "PHYLIP_msa";
    phylip_msa.formatGeneralName = "PHYLIP";
    phylip_msa.formatVariantName = "msa";
    phylip_msa.fileTypePatternInFirstLine = "\\s*2 \\d+";
    phylip_msa.commonHeaderFirstLine = "always";
    dlst[phylip_msa.formatName] = phylip_msa;

    MultypleAlignmentFileFormatDescript stockholm;
    stockholm.formatName = "STOCKHOLM";
    stockholm.formatGeneralName = "STOCKHOLM";
    stockholm.formatVariantName = "msa";
    stockholm.fileTypePatternInFirstLine = "# STOCKHOLM";
    dlst["STOCKHOLM"] = stockholm;

    MultypleAlignmentFileFormatDescript nexus_msa;
    nexus_msa.formatName = "NEXUS_msa";
    nexus_msa.formatGeneralName = "NEXUS";
    nexus_msa.formatVariantName = "msa";
    nexus_msa.fileTypePatternInFirstLine = "#NEXUS";
    dlst[nexus_msa.formatName] = nexus_msa;

    MultypleAlignmentFileFormatDescript clustal_msa;
    clustal_msa.formatName = "CLUSTAL_msa";
    clustal_msa.formatGeneralName = "CLUSTAL";
    clustal_msa.formatVariantName = "msa";
    clustal_msa.fileTypePatternInFirstLine = "CLUSTAL";
    dlst[clustal_msa.formatName] = clustal_msa;

    MultypleAlignmentFileFormatDescript maf_msa;
    maf_msa.formatName = "MAF_msa";
    maf_msa.formatGeneralName = "MAF";
    maf_msa.formatVariantName = "msa";
    maf_msa.fileTypePatternInFirstLine = "##maf ";
    dlst[maf_msa.formatName] = maf_msa;

    MultypleAlignmentFileFormatDescript simple_msa;
    simple_msa.formatName = "SIMPLE_msa";
    simple_msa.formatGeneralName = "SIMPLE";
    simple_msa.formatVariantName = "msa";
    simple_msa.fileTypePatternInFirstLine = "##########";
    dlst[simple_msa.formatName] = simple_msa;

    MultypleAlignmentFileFormatDescript srs_msa;
    srs_msa.formatName = "SRS_msa";
    srs_msa.formatGeneralName = "SRS";
    srs_msa.formatVariantName = "msa";
    srs_msa.fileTypePatternInFirstLine = "##########";
    dlst[srs_msa.formatName] = simple_msa;

    MultypleAlignmentFileFormatDescript sam_msa;
    sam_msa.formatName = "SAM_msa";
    sam_msa.formatGeneralName = "SAM";
    sam_msa.formatVariantName = "msa";
    dlst[sam_msa.formatName] = sam_msa;

    MultypleAlignmentFileFormatDescript fasta_gap;
    fasta_gap.formatName = "FASTA_gap";
    fasta_gap.formatGeneralName = "FASTA";
    fasta_gap.formatVariantName = "gaps";
    dlst[fasta_gap.formatName] = fasta_gap;
}