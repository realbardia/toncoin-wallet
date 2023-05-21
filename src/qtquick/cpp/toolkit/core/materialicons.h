#ifndef MATERIALICONS_H
#define MATERIALICONS_H

#include <QObject>
#include <QString>
#include <QFontDatabase>
#include <QVariantMap>

class MaterialIcons: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString family MEMBER mdi_family CONSTANT)
    Q_PROPERTY(QString mdi_access_point MEMBER mdi_access_point CONSTANT)
    Q_PROPERTY(QString mdi_access_point_network MEMBER mdi_access_point_network CONSTANT)
    Q_PROPERTY(QString mdi_access_point_network_off MEMBER mdi_access_point_network_off CONSTANT)
    Q_PROPERTY(QString mdi_account MEMBER mdi_account CONSTANT)
    Q_PROPERTY(QString mdi_account_alert MEMBER mdi_account_alert CONSTANT)
    Q_PROPERTY(QString mdi_account_alert_outline MEMBER mdi_account_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_arrow_left MEMBER mdi_account_arrow_left CONSTANT)
    Q_PROPERTY(QString mdi_account_arrow_left_outline MEMBER mdi_account_arrow_left_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_arrow_right MEMBER mdi_account_arrow_right CONSTANT)
    Q_PROPERTY(QString mdi_account_arrow_right_outline MEMBER mdi_account_arrow_right_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_badge MEMBER mdi_account_badge CONSTANT)
    Q_PROPERTY(QString mdi_account_badge_alert MEMBER mdi_account_badge_alert CONSTANT)
    Q_PROPERTY(QString mdi_account_badge_alert_outline MEMBER mdi_account_badge_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_badge_outline MEMBER mdi_account_badge_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_box MEMBER mdi_account_box CONSTANT)
    Q_PROPERTY(QString mdi_account_box_multiple MEMBER mdi_account_box_multiple CONSTANT)
    Q_PROPERTY(QString mdi_account_box_outline MEMBER mdi_account_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_card_details MEMBER mdi_account_card_details CONSTANT)
    Q_PROPERTY(QString mdi_account_card_details_outline MEMBER mdi_account_card_details_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_check MEMBER mdi_account_check CONSTANT)
    Q_PROPERTY(QString mdi_account_check_outline MEMBER mdi_account_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_child MEMBER mdi_account_child CONSTANT)
    Q_PROPERTY(QString mdi_account_child_circle MEMBER mdi_account_child_circle CONSTANT)
    Q_PROPERTY(QString mdi_account_circle MEMBER mdi_account_circle CONSTANT)
    Q_PROPERTY(QString mdi_account_circle_outline MEMBER mdi_account_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_clock MEMBER mdi_account_clock CONSTANT)
    Q_PROPERTY(QString mdi_account_clock_outline MEMBER mdi_account_clock_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_convert MEMBER mdi_account_convert CONSTANT)
    Q_PROPERTY(QString mdi_account_details MEMBER mdi_account_details CONSTANT)
    Q_PROPERTY(QString mdi_account_edit MEMBER mdi_account_edit CONSTANT)
    Q_PROPERTY(QString mdi_account_group MEMBER mdi_account_group CONSTANT)
    Q_PROPERTY(QString mdi_account_group_outline MEMBER mdi_account_group_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_heart MEMBER mdi_account_heart CONSTANT)
    Q_PROPERTY(QString mdi_account_heart_outline MEMBER mdi_account_heart_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_key MEMBER mdi_account_key CONSTANT)
    Q_PROPERTY(QString mdi_account_key_outline MEMBER mdi_account_key_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_minus MEMBER mdi_account_minus CONSTANT)
    Q_PROPERTY(QString mdi_account_minus_outline MEMBER mdi_account_minus_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_multiple MEMBER mdi_account_multiple CONSTANT)
    Q_PROPERTY(QString mdi_account_multiple_check MEMBER mdi_account_multiple_check CONSTANT)
    Q_PROPERTY(QString mdi_account_multiple_minus MEMBER mdi_account_multiple_minus CONSTANT)
    Q_PROPERTY(QString mdi_account_multiple_minus_outline MEMBER mdi_account_multiple_minus_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_multiple_outline MEMBER mdi_account_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_multiple_plus MEMBER mdi_account_multiple_plus CONSTANT)
    Q_PROPERTY(QString mdi_account_multiple_plus_outline MEMBER mdi_account_multiple_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_network MEMBER mdi_account_network CONSTANT)
    Q_PROPERTY(QString mdi_account_network_outline MEMBER mdi_account_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_off MEMBER mdi_account_off CONSTANT)
    Q_PROPERTY(QString mdi_account_off_outline MEMBER mdi_account_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_outline MEMBER mdi_account_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_plus MEMBER mdi_account_plus CONSTANT)
    Q_PROPERTY(QString mdi_account_plus_outline MEMBER mdi_account_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_question MEMBER mdi_account_question CONSTANT)
    Q_PROPERTY(QString mdi_account_question_outline MEMBER mdi_account_question_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_remove MEMBER mdi_account_remove CONSTANT)
    Q_PROPERTY(QString mdi_account_remove_outline MEMBER mdi_account_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_search MEMBER mdi_account_search CONSTANT)
    Q_PROPERTY(QString mdi_account_search_outline MEMBER mdi_account_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_settings MEMBER mdi_account_settings CONSTANT)
    Q_PROPERTY(QString mdi_account_star MEMBER mdi_account_star CONSTANT)
    Q_PROPERTY(QString mdi_account_star_outline MEMBER mdi_account_star_outline CONSTANT)
    Q_PROPERTY(QString mdi_account_supervisor MEMBER mdi_account_supervisor CONSTANT)
    Q_PROPERTY(QString mdi_account_supervisor_circle MEMBER mdi_account_supervisor_circle CONSTANT)
    Q_PROPERTY(QString mdi_account_switch MEMBER mdi_account_switch CONSTANT)
    Q_PROPERTY(QString mdi_account_tie MEMBER mdi_account_tie CONSTANT)
    Q_PROPERTY(QString mdi_accusoft MEMBER mdi_accusoft CONSTANT)
    Q_PROPERTY(QString mdi_adchoices MEMBER mdi_adchoices CONSTANT)
    Q_PROPERTY(QString mdi_adjust MEMBER mdi_adjust CONSTANT)
    Q_PROPERTY(QString mdi_adobe MEMBER mdi_adobe CONSTANT)
    Q_PROPERTY(QString mdi_air_conditioner MEMBER mdi_air_conditioner CONSTANT)
    Q_PROPERTY(QString mdi_air_filter MEMBER mdi_air_filter CONSTANT)
    Q_PROPERTY(QString mdi_air_horn MEMBER mdi_air_horn CONSTANT)
    Q_PROPERTY(QString mdi_air_purifier MEMBER mdi_air_purifier CONSTANT)
    Q_PROPERTY(QString mdi_airbag MEMBER mdi_airbag CONSTANT)
    Q_PROPERTY(QString mdi_airballoon MEMBER mdi_airballoon CONSTANT)
    Q_PROPERTY(QString mdi_airplane MEMBER mdi_airplane CONSTANT)
    Q_PROPERTY(QString mdi_airplane_landing MEMBER mdi_airplane_landing CONSTANT)
    Q_PROPERTY(QString mdi_airplane_off MEMBER mdi_airplane_off CONSTANT)
    Q_PROPERTY(QString mdi_airplane_takeoff MEMBER mdi_airplane_takeoff CONSTANT)
    Q_PROPERTY(QString mdi_airplay MEMBER mdi_airplay CONSTANT)
    Q_PROPERTY(QString mdi_airport MEMBER mdi_airport CONSTANT)
    Q_PROPERTY(QString mdi_alarm MEMBER mdi_alarm CONSTANT)
    Q_PROPERTY(QString mdi_alarm_bell MEMBER mdi_alarm_bell CONSTANT)
    Q_PROPERTY(QString mdi_alarm_check MEMBER mdi_alarm_check CONSTANT)
    Q_PROPERTY(QString mdi_alarm_light MEMBER mdi_alarm_light CONSTANT)
    Q_PROPERTY(QString mdi_alarm_light_outline MEMBER mdi_alarm_light_outline CONSTANT)
    Q_PROPERTY(QString mdi_alarm_multiple MEMBER mdi_alarm_multiple CONSTANT)
    Q_PROPERTY(QString mdi_alarm_off MEMBER mdi_alarm_off CONSTANT)
    Q_PROPERTY(QString mdi_alarm_plus MEMBER mdi_alarm_plus CONSTANT)
    Q_PROPERTY(QString mdi_alarm_snooze MEMBER mdi_alarm_snooze CONSTANT)
    Q_PROPERTY(QString mdi_album MEMBER mdi_album CONSTANT)
    Q_PROPERTY(QString mdi_alert MEMBER mdi_alert CONSTANT)
    Q_PROPERTY(QString mdi_alert_box MEMBER mdi_alert_box CONSTANT)
    Q_PROPERTY(QString mdi_alert_box_outline MEMBER mdi_alert_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alert_circle MEMBER mdi_alert_circle CONSTANT)
    Q_PROPERTY(QString mdi_alert_circle_outline MEMBER mdi_alert_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alert_decagram MEMBER mdi_alert_decagram CONSTANT)
    Q_PROPERTY(QString mdi_alert_decagram_outline MEMBER mdi_alert_decagram_outline CONSTANT)
    Q_PROPERTY(QString mdi_alert_octagon MEMBER mdi_alert_octagon CONSTANT)
    Q_PROPERTY(QString mdi_alert_octagon_outline MEMBER mdi_alert_octagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_alert_octagram MEMBER mdi_alert_octagram CONSTANT)
    Q_PROPERTY(QString mdi_alert_octagram_outline MEMBER mdi_alert_octagram_outline CONSTANT)
    Q_PROPERTY(QString mdi_alert_outline MEMBER mdi_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_alien MEMBER mdi_alien CONSTANT)
    Q_PROPERTY(QString mdi_all_inclusive MEMBER mdi_all_inclusive CONSTANT)
    Q_PROPERTY(QString mdi_alpha MEMBER mdi_alpha CONSTANT)
    Q_PROPERTY(QString mdi_alpha_a MEMBER mdi_alpha_a CONSTANT)
    Q_PROPERTY(QString mdi_alpha_a_box MEMBER mdi_alpha_a_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_a_box_outline MEMBER mdi_alpha_a_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_a_circle MEMBER mdi_alpha_a_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_a_circle_outline MEMBER mdi_alpha_a_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_b MEMBER mdi_alpha_b CONSTANT)
    Q_PROPERTY(QString mdi_alpha_b_box MEMBER mdi_alpha_b_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_b_box_outline MEMBER mdi_alpha_b_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_b_circle MEMBER mdi_alpha_b_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_b_circle_outline MEMBER mdi_alpha_b_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_c MEMBER mdi_alpha_c CONSTANT)
    Q_PROPERTY(QString mdi_alpha_c_box MEMBER mdi_alpha_c_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_c_box_outline MEMBER mdi_alpha_c_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_c_circle MEMBER mdi_alpha_c_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_c_circle_outline MEMBER mdi_alpha_c_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_d MEMBER mdi_alpha_d CONSTANT)
    Q_PROPERTY(QString mdi_alpha_d_box MEMBER mdi_alpha_d_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_d_box_outline MEMBER mdi_alpha_d_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_d_circle MEMBER mdi_alpha_d_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_d_circle_outline MEMBER mdi_alpha_d_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_e MEMBER mdi_alpha_e CONSTANT)
    Q_PROPERTY(QString mdi_alpha_e_box MEMBER mdi_alpha_e_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_e_box_outline MEMBER mdi_alpha_e_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_e_circle MEMBER mdi_alpha_e_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_e_circle_outline MEMBER mdi_alpha_e_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_f MEMBER mdi_alpha_f CONSTANT)
    Q_PROPERTY(QString mdi_alpha_f_box MEMBER mdi_alpha_f_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_f_box_outline MEMBER mdi_alpha_f_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_f_circle MEMBER mdi_alpha_f_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_f_circle_outline MEMBER mdi_alpha_f_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_g MEMBER mdi_alpha_g CONSTANT)
    Q_PROPERTY(QString mdi_alpha_g_box MEMBER mdi_alpha_g_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_g_box_outline MEMBER mdi_alpha_g_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_g_circle MEMBER mdi_alpha_g_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_g_circle_outline MEMBER mdi_alpha_g_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_h MEMBER mdi_alpha_h CONSTANT)
    Q_PROPERTY(QString mdi_alpha_h_box MEMBER mdi_alpha_h_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_h_box_outline MEMBER mdi_alpha_h_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_h_circle MEMBER mdi_alpha_h_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_h_circle_outline MEMBER mdi_alpha_h_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_i MEMBER mdi_alpha_i CONSTANT)
    Q_PROPERTY(QString mdi_alpha_i_box MEMBER mdi_alpha_i_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_i_box_outline MEMBER mdi_alpha_i_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_i_circle MEMBER mdi_alpha_i_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_i_circle_outline MEMBER mdi_alpha_i_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_j MEMBER mdi_alpha_j CONSTANT)
    Q_PROPERTY(QString mdi_alpha_j_box MEMBER mdi_alpha_j_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_j_box_outline MEMBER mdi_alpha_j_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_j_circle MEMBER mdi_alpha_j_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_j_circle_outline MEMBER mdi_alpha_j_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_k MEMBER mdi_alpha_k CONSTANT)
    Q_PROPERTY(QString mdi_alpha_k_box MEMBER mdi_alpha_k_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_k_box_outline MEMBER mdi_alpha_k_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_k_circle MEMBER mdi_alpha_k_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_k_circle_outline MEMBER mdi_alpha_k_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_l MEMBER mdi_alpha_l CONSTANT)
    Q_PROPERTY(QString mdi_alpha_l_box MEMBER mdi_alpha_l_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_l_box_outline MEMBER mdi_alpha_l_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_l_circle MEMBER mdi_alpha_l_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_l_circle_outline MEMBER mdi_alpha_l_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_m MEMBER mdi_alpha_m CONSTANT)
    Q_PROPERTY(QString mdi_alpha_m_box MEMBER mdi_alpha_m_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_m_box_outline MEMBER mdi_alpha_m_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_m_circle MEMBER mdi_alpha_m_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_m_circle_outline MEMBER mdi_alpha_m_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_n MEMBER mdi_alpha_n CONSTANT)
    Q_PROPERTY(QString mdi_alpha_n_box MEMBER mdi_alpha_n_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_n_box_outline MEMBER mdi_alpha_n_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_n_circle MEMBER mdi_alpha_n_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_n_circle_outline MEMBER mdi_alpha_n_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_o MEMBER mdi_alpha_o CONSTANT)
    Q_PROPERTY(QString mdi_alpha_o_box MEMBER mdi_alpha_o_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_o_box_outline MEMBER mdi_alpha_o_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_o_circle MEMBER mdi_alpha_o_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_o_circle_outline MEMBER mdi_alpha_o_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_p MEMBER mdi_alpha_p CONSTANT)
    Q_PROPERTY(QString mdi_alpha_p_box MEMBER mdi_alpha_p_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_p_box_outline MEMBER mdi_alpha_p_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_p_circle MEMBER mdi_alpha_p_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_p_circle_outline MEMBER mdi_alpha_p_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_q MEMBER mdi_alpha_q CONSTANT)
    Q_PROPERTY(QString mdi_alpha_q_box MEMBER mdi_alpha_q_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_q_box_outline MEMBER mdi_alpha_q_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_q_circle MEMBER mdi_alpha_q_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_q_circle_outline MEMBER mdi_alpha_q_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_r MEMBER mdi_alpha_r CONSTANT)
    Q_PROPERTY(QString mdi_alpha_r_box MEMBER mdi_alpha_r_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_r_box_outline MEMBER mdi_alpha_r_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_r_circle MEMBER mdi_alpha_r_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_r_circle_outline MEMBER mdi_alpha_r_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_s MEMBER mdi_alpha_s CONSTANT)
    Q_PROPERTY(QString mdi_alpha_s_box MEMBER mdi_alpha_s_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_s_box_outline MEMBER mdi_alpha_s_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_s_circle MEMBER mdi_alpha_s_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_s_circle_outline MEMBER mdi_alpha_s_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_t MEMBER mdi_alpha_t CONSTANT)
    Q_PROPERTY(QString mdi_alpha_t_box MEMBER mdi_alpha_t_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_t_box_outline MEMBER mdi_alpha_t_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_t_circle MEMBER mdi_alpha_t_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_t_circle_outline MEMBER mdi_alpha_t_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_u MEMBER mdi_alpha_u CONSTANT)
    Q_PROPERTY(QString mdi_alpha_u_box MEMBER mdi_alpha_u_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_u_box_outline MEMBER mdi_alpha_u_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_u_circle MEMBER mdi_alpha_u_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_u_circle_outline MEMBER mdi_alpha_u_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_v MEMBER mdi_alpha_v CONSTANT)
    Q_PROPERTY(QString mdi_alpha_v_box MEMBER mdi_alpha_v_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_v_box_outline MEMBER mdi_alpha_v_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_v_circle MEMBER mdi_alpha_v_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_v_circle_outline MEMBER mdi_alpha_v_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_w MEMBER mdi_alpha_w CONSTANT)
    Q_PROPERTY(QString mdi_alpha_w_box MEMBER mdi_alpha_w_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_w_box_outline MEMBER mdi_alpha_w_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_w_circle MEMBER mdi_alpha_w_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_w_circle_outline MEMBER mdi_alpha_w_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_x MEMBER mdi_alpha_x CONSTANT)
    Q_PROPERTY(QString mdi_alpha_x_box MEMBER mdi_alpha_x_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_x_box_outline MEMBER mdi_alpha_x_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_x_circle MEMBER mdi_alpha_x_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_x_circle_outline MEMBER mdi_alpha_x_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_y MEMBER mdi_alpha_y CONSTANT)
    Q_PROPERTY(QString mdi_alpha_y_box MEMBER mdi_alpha_y_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_y_box_outline MEMBER mdi_alpha_y_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_y_circle MEMBER mdi_alpha_y_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_y_circle_outline MEMBER mdi_alpha_y_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_z MEMBER mdi_alpha_z CONSTANT)
    Q_PROPERTY(QString mdi_alpha_z_box MEMBER mdi_alpha_z_box CONSTANT)
    Q_PROPERTY(QString mdi_alpha_z_box_outline MEMBER mdi_alpha_z_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_alpha_z_circle MEMBER mdi_alpha_z_circle CONSTANT)
    Q_PROPERTY(QString mdi_alpha_z_circle_outline MEMBER mdi_alpha_z_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_alphabetical MEMBER mdi_alphabetical CONSTANT)
    Q_PROPERTY(QString mdi_altimeter MEMBER mdi_altimeter CONSTANT)
    Q_PROPERTY(QString mdi_amazon MEMBER mdi_amazon CONSTANT)
    Q_PROPERTY(QString mdi_amazon_alexa MEMBER mdi_amazon_alexa CONSTANT)
    Q_PROPERTY(QString mdi_amazon_drive MEMBER mdi_amazon_drive CONSTANT)
    Q_PROPERTY(QString mdi_ambulance MEMBER mdi_ambulance CONSTANT)
    Q_PROPERTY(QString mdi_ammunition MEMBER mdi_ammunition CONSTANT)
    Q_PROPERTY(QString mdi_ampersand MEMBER mdi_ampersand CONSTANT)
    Q_PROPERTY(QString mdi_amplifier MEMBER mdi_amplifier CONSTANT)
    Q_PROPERTY(QString mdi_anchor MEMBER mdi_anchor CONSTANT)
    Q_PROPERTY(QString mdi_android MEMBER mdi_android CONSTANT)
    Q_PROPERTY(QString mdi_android_auto MEMBER mdi_android_auto CONSTANT)
    Q_PROPERTY(QString mdi_android_debug_bridge MEMBER mdi_android_debug_bridge CONSTANT)
    Q_PROPERTY(QString mdi_android_head MEMBER mdi_android_head CONSTANT)
    Q_PROPERTY(QString mdi_android_messages MEMBER mdi_android_messages CONSTANT)
    Q_PROPERTY(QString mdi_android_studio MEMBER mdi_android_studio CONSTANT)
    Q_PROPERTY(QString mdi_angle_acute MEMBER mdi_angle_acute CONSTANT)
    Q_PROPERTY(QString mdi_angle_obtuse MEMBER mdi_angle_obtuse CONSTANT)
    Q_PROPERTY(QString mdi_angle_right MEMBER mdi_angle_right CONSTANT)
    Q_PROPERTY(QString mdi_angular MEMBER mdi_angular CONSTANT)
    Q_PROPERTY(QString mdi_angularjs MEMBER mdi_angularjs CONSTANT)
    Q_PROPERTY(QString mdi_animation MEMBER mdi_animation CONSTANT)
    Q_PROPERTY(QString mdi_animation_outline MEMBER mdi_animation_outline CONSTANT)
    Q_PROPERTY(QString mdi_animation_play MEMBER mdi_animation_play CONSTANT)
    Q_PROPERTY(QString mdi_animation_play_outline MEMBER mdi_animation_play_outline CONSTANT)
    Q_PROPERTY(QString mdi_anvil MEMBER mdi_anvil CONSTANT)
    Q_PROPERTY(QString mdi_apple MEMBER mdi_apple CONSTANT)
    Q_PROPERTY(QString mdi_apple_finder MEMBER mdi_apple_finder CONSTANT)
    Q_PROPERTY(QString mdi_apple_icloud MEMBER mdi_apple_icloud CONSTANT)
    Q_PROPERTY(QString mdi_apple_ios MEMBER mdi_apple_ios CONSTANT)
    Q_PROPERTY(QString mdi_apple_keyboard_caps MEMBER mdi_apple_keyboard_caps CONSTANT)
    Q_PROPERTY(QString mdi_apple_keyboard_command MEMBER mdi_apple_keyboard_command CONSTANT)
    Q_PROPERTY(QString mdi_apple_keyboard_control MEMBER mdi_apple_keyboard_control CONSTANT)
    Q_PROPERTY(QString mdi_apple_keyboard_option MEMBER mdi_apple_keyboard_option CONSTANT)
    Q_PROPERTY(QString mdi_apple_keyboard_shift MEMBER mdi_apple_keyboard_shift CONSTANT)
    Q_PROPERTY(QString mdi_apple_safari MEMBER mdi_apple_safari CONSTANT)
    Q_PROPERTY(QString mdi_application MEMBER mdi_application CONSTANT)
    Q_PROPERTY(QString mdi_application_export MEMBER mdi_application_export CONSTANT)
    Q_PROPERTY(QString mdi_application_import MEMBER mdi_application_import CONSTANT)
    Q_PROPERTY(QString mdi_apps MEMBER mdi_apps CONSTANT)
    Q_PROPERTY(QString mdi_apps_box MEMBER mdi_apps_box CONSTANT)
    Q_PROPERTY(QString mdi_arch MEMBER mdi_arch CONSTANT)
    Q_PROPERTY(QString mdi_archive MEMBER mdi_archive CONSTANT)
    Q_PROPERTY(QString mdi_arrange_bring_forward MEMBER mdi_arrange_bring_forward CONSTANT)
    Q_PROPERTY(QString mdi_arrange_bring_to_front MEMBER mdi_arrange_bring_to_front CONSTANT)
    Q_PROPERTY(QString mdi_arrange_send_backward MEMBER mdi_arrange_send_backward CONSTANT)
    Q_PROPERTY(QString mdi_arrange_send_to_back MEMBER mdi_arrange_send_to_back CONSTANT)
    Q_PROPERTY(QString mdi_arrow_all MEMBER mdi_arrow_all CONSTANT)
    Q_PROPERTY(QString mdi_arrow_bottom_left MEMBER mdi_arrow_bottom_left CONSTANT)
    Q_PROPERTY(QString mdi_arrow_bottom_left_bold_outline MEMBER mdi_arrow_bottom_left_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_bottom_left_thick MEMBER mdi_arrow_bottom_left_thick CONSTANT)
    Q_PROPERTY(QString mdi_arrow_bottom_right MEMBER mdi_arrow_bottom_right CONSTANT)
    Q_PROPERTY(QString mdi_arrow_bottom_right_bold_outline MEMBER mdi_arrow_bottom_right_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_bottom_right_thick MEMBER mdi_arrow_bottom_right_thick CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse MEMBER mdi_arrow_collapse CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse_all MEMBER mdi_arrow_collapse_all CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse_down MEMBER mdi_arrow_collapse_down CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse_horizontal MEMBER mdi_arrow_collapse_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse_left MEMBER mdi_arrow_collapse_left CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse_right MEMBER mdi_arrow_collapse_right CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse_up MEMBER mdi_arrow_collapse_up CONSTANT)
    Q_PROPERTY(QString mdi_arrow_collapse_vertical MEMBER mdi_arrow_collapse_vertical CONSTANT)
    Q_PROPERTY(QString mdi_arrow_decision MEMBER mdi_arrow_decision CONSTANT)
    Q_PROPERTY(QString mdi_arrow_decision_auto MEMBER mdi_arrow_decision_auto CONSTANT)
    Q_PROPERTY(QString mdi_arrow_decision_auto_outline MEMBER mdi_arrow_decision_auto_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_decision_outline MEMBER mdi_arrow_decision_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down MEMBER mdi_arrow_down CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_bold MEMBER mdi_arrow_down_bold CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_bold_box MEMBER mdi_arrow_down_bold_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_bold_box_outline MEMBER mdi_arrow_down_bold_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_bold_circle MEMBER mdi_arrow_down_bold_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_bold_circle_outline MEMBER mdi_arrow_down_bold_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_bold_hexagon_outline MEMBER mdi_arrow_down_bold_hexagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_bold_outline MEMBER mdi_arrow_down_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_box MEMBER mdi_arrow_down_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_circle MEMBER mdi_arrow_down_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_circle_outline MEMBER mdi_arrow_down_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_drop_circle MEMBER mdi_arrow_down_drop_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_drop_circle_outline MEMBER mdi_arrow_down_drop_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_down_thick MEMBER mdi_arrow_down_thick CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand MEMBER mdi_arrow_expand CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand_all MEMBER mdi_arrow_expand_all CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand_down MEMBER mdi_arrow_expand_down CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand_horizontal MEMBER mdi_arrow_expand_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand_left MEMBER mdi_arrow_expand_left CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand_right MEMBER mdi_arrow_expand_right CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand_up MEMBER mdi_arrow_expand_up CONSTANT)
    Q_PROPERTY(QString mdi_arrow_expand_vertical MEMBER mdi_arrow_expand_vertical CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left MEMBER mdi_arrow_left CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_bold MEMBER mdi_arrow_left_bold CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_bold_box MEMBER mdi_arrow_left_bold_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_bold_box_outline MEMBER mdi_arrow_left_bold_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_bold_circle MEMBER mdi_arrow_left_bold_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_bold_circle_outline MEMBER mdi_arrow_left_bold_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_bold_hexagon_outline MEMBER mdi_arrow_left_bold_hexagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_bold_outline MEMBER mdi_arrow_left_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_box MEMBER mdi_arrow_left_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_circle MEMBER mdi_arrow_left_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_circle_outline MEMBER mdi_arrow_left_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_drop_circle MEMBER mdi_arrow_left_drop_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_drop_circle_outline MEMBER mdi_arrow_left_drop_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_right_bold_outline MEMBER mdi_arrow_left_right_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_left_thick MEMBER mdi_arrow_left_thick CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right MEMBER mdi_arrow_right CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_bold MEMBER mdi_arrow_right_bold CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_bold_box MEMBER mdi_arrow_right_bold_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_bold_box_outline MEMBER mdi_arrow_right_bold_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_bold_circle MEMBER mdi_arrow_right_bold_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_bold_circle_outline MEMBER mdi_arrow_right_bold_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_bold_hexagon_outline MEMBER mdi_arrow_right_bold_hexagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_bold_outline MEMBER mdi_arrow_right_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_box MEMBER mdi_arrow_right_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_circle MEMBER mdi_arrow_right_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_circle_outline MEMBER mdi_arrow_right_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_drop_circle MEMBER mdi_arrow_right_drop_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_drop_circle_outline MEMBER mdi_arrow_right_drop_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_right_thick MEMBER mdi_arrow_right_thick CONSTANT)
    Q_PROPERTY(QString mdi_arrow_split_horizontal MEMBER mdi_arrow_split_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_arrow_split_vertical MEMBER mdi_arrow_split_vertical CONSTANT)
    Q_PROPERTY(QString mdi_arrow_top_left MEMBER mdi_arrow_top_left CONSTANT)
    Q_PROPERTY(QString mdi_arrow_top_left_bold_outline MEMBER mdi_arrow_top_left_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_top_left_thick MEMBER mdi_arrow_top_left_thick CONSTANT)
    Q_PROPERTY(QString mdi_arrow_top_right MEMBER mdi_arrow_top_right CONSTANT)
    Q_PROPERTY(QString mdi_arrow_top_right_bold_outline MEMBER mdi_arrow_top_right_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_top_right_thick MEMBER mdi_arrow_top_right_thick CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up MEMBER mdi_arrow_up CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_bold MEMBER mdi_arrow_up_bold CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_bold_box MEMBER mdi_arrow_up_bold_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_bold_box_outline MEMBER mdi_arrow_up_bold_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_bold_circle MEMBER mdi_arrow_up_bold_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_bold_circle_outline MEMBER mdi_arrow_up_bold_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_bold_hexagon_outline MEMBER mdi_arrow_up_bold_hexagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_bold_outline MEMBER mdi_arrow_up_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_box MEMBER mdi_arrow_up_box CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_circle MEMBER mdi_arrow_up_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_circle_outline MEMBER mdi_arrow_up_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_down_bold_outline MEMBER mdi_arrow_up_down_bold_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_drop_circle MEMBER mdi_arrow_up_drop_circle CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_drop_circle_outline MEMBER mdi_arrow_up_drop_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_arrow_up_thick MEMBER mdi_arrow_up_thick CONSTANT)
    Q_PROPERTY(QString mdi_artist MEMBER mdi_artist CONSTANT)
    Q_PROPERTY(QString mdi_artist_outline MEMBER mdi_artist_outline CONSTANT)
    Q_PROPERTY(QString mdi_artstation MEMBER mdi_artstation CONSTANT)
    Q_PROPERTY(QString mdi_aspect_ratio MEMBER mdi_aspect_ratio CONSTANT)
    Q_PROPERTY(QString mdi_assistant MEMBER mdi_assistant CONSTANT)
    Q_PROPERTY(QString mdi_asterisk MEMBER mdi_asterisk CONSTANT)
    Q_PROPERTY(QString mdi_at MEMBER mdi_at CONSTANT)
    Q_PROPERTY(QString mdi_atlassian MEMBER mdi_atlassian CONSTANT)
    Q_PROPERTY(QString mdi_atm MEMBER mdi_atm CONSTANT)
    Q_PROPERTY(QString mdi_atom MEMBER mdi_atom CONSTANT)
    Q_PROPERTY(QString mdi_attachment MEMBER mdi_attachment CONSTANT)
    Q_PROPERTY(QString mdi_audio_video MEMBER mdi_audio_video CONSTANT)
    Q_PROPERTY(QString mdi_audiobook MEMBER mdi_audiobook CONSTANT)
    Q_PROPERTY(QString mdi_augmented_reality MEMBER mdi_augmented_reality CONSTANT)
    Q_PROPERTY(QString mdi_auto_fix MEMBER mdi_auto_fix CONSTANT)
    Q_PROPERTY(QString mdi_auto_upload MEMBER mdi_auto_upload CONSTANT)
    Q_PROPERTY(QString mdi_autorenew MEMBER mdi_autorenew CONSTANT)
    Q_PROPERTY(QString mdi_av_timer MEMBER mdi_av_timer CONSTANT)
    Q_PROPERTY(QString mdi_axe MEMBER mdi_axe CONSTANT)
    Q_PROPERTY(QString mdi_axis MEMBER mdi_axis CONSTANT)
    Q_PROPERTY(QString mdi_axis_arrow MEMBER mdi_axis_arrow CONSTANT)
    Q_PROPERTY(QString mdi_axis_arrow_lock MEMBER mdi_axis_arrow_lock CONSTANT)
    Q_PROPERTY(QString mdi_axis_lock MEMBER mdi_axis_lock CONSTANT)
    Q_PROPERTY(QString mdi_axis_x_arrow MEMBER mdi_axis_x_arrow CONSTANT)
    Q_PROPERTY(QString mdi_axis_x_arrow_lock MEMBER mdi_axis_x_arrow_lock CONSTANT)
    Q_PROPERTY(QString mdi_axis_x_rotate_clockwise MEMBER mdi_axis_x_rotate_clockwise CONSTANT)
    Q_PROPERTY(QString mdi_axis_x_rotate_counterclockwise MEMBER mdi_axis_x_rotate_counterclockwise CONSTANT)
    Q_PROPERTY(QString mdi_axis_x_y_arrow_lock MEMBER mdi_axis_x_y_arrow_lock CONSTANT)
    Q_PROPERTY(QString mdi_axis_y_arrow MEMBER mdi_axis_y_arrow CONSTANT)
    Q_PROPERTY(QString mdi_axis_y_arrow_lock MEMBER mdi_axis_y_arrow_lock CONSTANT)
    Q_PROPERTY(QString mdi_axis_y_rotate_clockwise MEMBER mdi_axis_y_rotate_clockwise CONSTANT)
    Q_PROPERTY(QString mdi_axis_y_rotate_counterclockwise MEMBER mdi_axis_y_rotate_counterclockwise CONSTANT)
    Q_PROPERTY(QString mdi_axis_z_arrow MEMBER mdi_axis_z_arrow CONSTANT)
    Q_PROPERTY(QString mdi_axis_z_arrow_lock MEMBER mdi_axis_z_arrow_lock CONSTANT)
    Q_PROPERTY(QString mdi_axis_z_rotate_clockwise MEMBER mdi_axis_z_rotate_clockwise CONSTANT)
    Q_PROPERTY(QString mdi_axis_z_rotate_counterclockwise MEMBER mdi_axis_z_rotate_counterclockwise CONSTANT)
    Q_PROPERTY(QString mdi_azure MEMBER mdi_azure CONSTANT)
    Q_PROPERTY(QString mdi_babel MEMBER mdi_babel CONSTANT)
    Q_PROPERTY(QString mdi_baby MEMBER mdi_baby CONSTANT)
    Q_PROPERTY(QString mdi_baby_buggy MEMBER mdi_baby_buggy CONSTANT)
    Q_PROPERTY(QString mdi_backburger MEMBER mdi_backburger CONSTANT)
    Q_PROPERTY(QString mdi_backspace MEMBER mdi_backspace CONSTANT)
    Q_PROPERTY(QString mdi_backspace_outline MEMBER mdi_backspace_outline CONSTANT)
    Q_PROPERTY(QString mdi_backup_restore MEMBER mdi_backup_restore CONSTANT)
    Q_PROPERTY(QString mdi_badminton MEMBER mdi_badminton CONSTANT)
    Q_PROPERTY(QString mdi_balloon MEMBER mdi_balloon CONSTANT)
    Q_PROPERTY(QString mdi_ballot MEMBER mdi_ballot CONSTANT)
    Q_PROPERTY(QString mdi_ballot_outline MEMBER mdi_ballot_outline CONSTANT)
    Q_PROPERTY(QString mdi_ballot_recount MEMBER mdi_ballot_recount CONSTANT)
    Q_PROPERTY(QString mdi_ballot_recount_outline MEMBER mdi_ballot_recount_outline CONSTANT)
    Q_PROPERTY(QString mdi_bandage MEMBER mdi_bandage CONSTANT)
    Q_PROPERTY(QString mdi_bandcamp MEMBER mdi_bandcamp CONSTANT)
    Q_PROPERTY(QString mdi_bank MEMBER mdi_bank CONSTANT)
    Q_PROPERTY(QString mdi_bank_minus MEMBER mdi_bank_minus CONSTANT)
    Q_PROPERTY(QString mdi_bank_plus MEMBER mdi_bank_plus CONSTANT)
    Q_PROPERTY(QString mdi_bank_remove MEMBER mdi_bank_remove CONSTANT)
    Q_PROPERTY(QString mdi_bank_transfer MEMBER mdi_bank_transfer CONSTANT)
    Q_PROPERTY(QString mdi_bank_transfer_in MEMBER mdi_bank_transfer_in CONSTANT)
    Q_PROPERTY(QString mdi_bank_transfer_out MEMBER mdi_bank_transfer_out CONSTANT)
    Q_PROPERTY(QString mdi_barcode MEMBER mdi_barcode CONSTANT)
    Q_PROPERTY(QString mdi_barcode_scan MEMBER mdi_barcode_scan CONSTANT)
    Q_PROPERTY(QString mdi_barley MEMBER mdi_barley CONSTANT)
    Q_PROPERTY(QString mdi_barley_off MEMBER mdi_barley_off CONSTANT)
    Q_PROPERTY(QString mdi_barn MEMBER mdi_barn CONSTANT)
    Q_PROPERTY(QString mdi_barrel MEMBER mdi_barrel CONSTANT)
    Q_PROPERTY(QString mdi_baseball MEMBER mdi_baseball CONSTANT)
    Q_PROPERTY(QString mdi_baseball_bat MEMBER mdi_baseball_bat CONSTANT)
    Q_PROPERTY(QString mdi_basecamp MEMBER mdi_basecamp CONSTANT)
    Q_PROPERTY(QString mdi_basket MEMBER mdi_basket CONSTANT)
    Q_PROPERTY(QString mdi_basket_fill MEMBER mdi_basket_fill CONSTANT)
    Q_PROPERTY(QString mdi_basket_unfill MEMBER mdi_basket_unfill CONSTANT)
    Q_PROPERTY(QString mdi_basketball MEMBER mdi_basketball CONSTANT)
    Q_PROPERTY(QString mdi_basketball_hoop MEMBER mdi_basketball_hoop CONSTANT)
    Q_PROPERTY(QString mdi_basketball_hoop_outline MEMBER mdi_basketball_hoop_outline CONSTANT)
    Q_PROPERTY(QString mdi_bat MEMBER mdi_bat CONSTANT)
    Q_PROPERTY(QString mdi_battery MEMBER mdi_battery CONSTANT)
    Q_PROPERTY(QString mdi_battery_10 MEMBER mdi_battery_10 CONSTANT)
    Q_PROPERTY(QString mdi_battery_10_bluetooth MEMBER mdi_battery_10_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_20 MEMBER mdi_battery_20 CONSTANT)
    Q_PROPERTY(QString mdi_battery_20_bluetooth MEMBER mdi_battery_20_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_30 MEMBER mdi_battery_30 CONSTANT)
    Q_PROPERTY(QString mdi_battery_30_bluetooth MEMBER mdi_battery_30_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_40 MEMBER mdi_battery_40 CONSTANT)
    Q_PROPERTY(QString mdi_battery_40_bluetooth MEMBER mdi_battery_40_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_50 MEMBER mdi_battery_50 CONSTANT)
    Q_PROPERTY(QString mdi_battery_50_bluetooth MEMBER mdi_battery_50_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_60 MEMBER mdi_battery_60 CONSTANT)
    Q_PROPERTY(QString mdi_battery_60_bluetooth MEMBER mdi_battery_60_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_70 MEMBER mdi_battery_70 CONSTANT)
    Q_PROPERTY(QString mdi_battery_70_bluetooth MEMBER mdi_battery_70_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_80 MEMBER mdi_battery_80 CONSTANT)
    Q_PROPERTY(QString mdi_battery_80_bluetooth MEMBER mdi_battery_80_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_90 MEMBER mdi_battery_90 CONSTANT)
    Q_PROPERTY(QString mdi_battery_90_bluetooth MEMBER mdi_battery_90_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_alert MEMBER mdi_battery_alert CONSTANT)
    Q_PROPERTY(QString mdi_battery_alert_bluetooth MEMBER mdi_battery_alert_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_bluetooth MEMBER mdi_battery_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battery_bluetooth_variant MEMBER mdi_battery_bluetooth_variant CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging MEMBER mdi_battery_charging CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_10 MEMBER mdi_battery_charging_10 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_100 MEMBER mdi_battery_charging_100 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_20 MEMBER mdi_battery_charging_20 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_30 MEMBER mdi_battery_charging_30 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_40 MEMBER mdi_battery_charging_40 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_50 MEMBER mdi_battery_charging_50 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_60 MEMBER mdi_battery_charging_60 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_70 MEMBER mdi_battery_charging_70 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_80 MEMBER mdi_battery_charging_80 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_90 MEMBER mdi_battery_charging_90 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_outline MEMBER mdi_battery_charging_outline CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless MEMBER mdi_battery_charging_wireless CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_10 MEMBER mdi_battery_charging_wireless_10 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_20 MEMBER mdi_battery_charging_wireless_20 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_30 MEMBER mdi_battery_charging_wireless_30 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_40 MEMBER mdi_battery_charging_wireless_40 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_50 MEMBER mdi_battery_charging_wireless_50 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_60 MEMBER mdi_battery_charging_wireless_60 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_70 MEMBER mdi_battery_charging_wireless_70 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_80 MEMBER mdi_battery_charging_wireless_80 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_90 MEMBER mdi_battery_charging_wireless_90 CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_alert MEMBER mdi_battery_charging_wireless_alert CONSTANT)
    Q_PROPERTY(QString mdi_battery_charging_wireless_outline MEMBER mdi_battery_charging_wireless_outline CONSTANT)
    Q_PROPERTY(QString mdi_battery_minus MEMBER mdi_battery_minus CONSTANT)
    Q_PROPERTY(QString mdi_battery_negative MEMBER mdi_battery_negative CONSTANT)
    Q_PROPERTY(QString mdi_battery_outline MEMBER mdi_battery_outline CONSTANT)
    Q_PROPERTY(QString mdi_battery_plus MEMBER mdi_battery_plus CONSTANT)
    Q_PROPERTY(QString mdi_battery_positive MEMBER mdi_battery_positive CONSTANT)
    Q_PROPERTY(QString mdi_battery_unknown MEMBER mdi_battery_unknown CONSTANT)
    Q_PROPERTY(QString mdi_battery_unknown_bluetooth MEMBER mdi_battery_unknown_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_battlenet MEMBER mdi_battlenet CONSTANT)
    Q_PROPERTY(QString mdi_beach MEMBER mdi_beach CONSTANT)
    Q_PROPERTY(QString mdi_beaker MEMBER mdi_beaker CONSTANT)
    Q_PROPERTY(QString mdi_beaker_outline MEMBER mdi_beaker_outline CONSTANT)
    Q_PROPERTY(QString mdi_beats MEMBER mdi_beats CONSTANT)
    Q_PROPERTY(QString mdi_bed_empty MEMBER mdi_bed_empty CONSTANT)
    Q_PROPERTY(QString mdi_beer MEMBER mdi_beer CONSTANT)
    Q_PROPERTY(QString mdi_behance MEMBER mdi_behance CONSTANT)
    Q_PROPERTY(QString mdi_bell MEMBER mdi_bell CONSTANT)
    Q_PROPERTY(QString mdi_bell_alert MEMBER mdi_bell_alert CONSTANT)
    Q_PROPERTY(QString mdi_bell_circle MEMBER mdi_bell_circle CONSTANT)
    Q_PROPERTY(QString mdi_bell_circle_outline MEMBER mdi_bell_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_bell_off MEMBER mdi_bell_off CONSTANT)
    Q_PROPERTY(QString mdi_bell_off_outline MEMBER mdi_bell_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_bell_outline MEMBER mdi_bell_outline CONSTANT)
    Q_PROPERTY(QString mdi_bell_plus MEMBER mdi_bell_plus CONSTANT)
    Q_PROPERTY(QString mdi_bell_plus_outline MEMBER mdi_bell_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_bell_ring MEMBER mdi_bell_ring CONSTANT)
    Q_PROPERTY(QString mdi_bell_ring_outline MEMBER mdi_bell_ring_outline CONSTANT)
    Q_PROPERTY(QString mdi_bell_sleep MEMBER mdi_bell_sleep CONSTANT)
    Q_PROPERTY(QString mdi_bell_sleep_outline MEMBER mdi_bell_sleep_outline CONSTANT)
    Q_PROPERTY(QString mdi_beta MEMBER mdi_beta CONSTANT)
    Q_PROPERTY(QString mdi_betamax MEMBER mdi_betamax CONSTANT)
    Q_PROPERTY(QString mdi_bible MEMBER mdi_bible CONSTANT)
    Q_PROPERTY(QString mdi_bike MEMBER mdi_bike CONSTANT)
    Q_PROPERTY(QString mdi_billiards MEMBER mdi_billiards CONSTANT)
    Q_PROPERTY(QString mdi_billiards_rack MEMBER mdi_billiards_rack CONSTANT)
    Q_PROPERTY(QString mdi_bing MEMBER mdi_bing CONSTANT)
    Q_PROPERTY(QString mdi_binoculars MEMBER mdi_binoculars CONSTANT)
    Q_PROPERTY(QString mdi_bio MEMBER mdi_bio CONSTANT)
    Q_PROPERTY(QString mdi_biohazard MEMBER mdi_biohazard CONSTANT)
    Q_PROPERTY(QString mdi_bitbucket MEMBER mdi_bitbucket CONSTANT)
    Q_PROPERTY(QString mdi_bitcoin MEMBER mdi_bitcoin CONSTANT)
    Q_PROPERTY(QString mdi_black_mesa MEMBER mdi_black_mesa CONSTANT)
    Q_PROPERTY(QString mdi_blackberry MEMBER mdi_blackberry CONSTANT)
    Q_PROPERTY(QString mdi_blender MEMBER mdi_blender CONSTANT)
    Q_PROPERTY(QString mdi_blender_software MEMBER mdi_blender_software CONSTANT)
    Q_PROPERTY(QString mdi_blinds MEMBER mdi_blinds CONSTANT)
    Q_PROPERTY(QString mdi_block_helper MEMBER mdi_block_helper CONSTANT)
    Q_PROPERTY(QString mdi_blogger MEMBER mdi_blogger CONSTANT)
    Q_PROPERTY(QString mdi_blood_bag MEMBER mdi_blood_bag CONSTANT)
    Q_PROPERTY(QString mdi_bluetooth MEMBER mdi_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_bluetooth_audio MEMBER mdi_bluetooth_audio CONSTANT)
    Q_PROPERTY(QString mdi_bluetooth_connect MEMBER mdi_bluetooth_connect CONSTANT)
    Q_PROPERTY(QString mdi_bluetooth_off MEMBER mdi_bluetooth_off CONSTANT)
    Q_PROPERTY(QString mdi_bluetooth_settings MEMBER mdi_bluetooth_settings CONSTANT)
    Q_PROPERTY(QString mdi_bluetooth_transfer MEMBER mdi_bluetooth_transfer CONSTANT)
    Q_PROPERTY(QString mdi_blur MEMBER mdi_blur CONSTANT)
    Q_PROPERTY(QString mdi_blur_linear MEMBER mdi_blur_linear CONSTANT)
    Q_PROPERTY(QString mdi_blur_off MEMBER mdi_blur_off CONSTANT)
    Q_PROPERTY(QString mdi_blur_radial MEMBER mdi_blur_radial CONSTANT)
    Q_PROPERTY(QString mdi_bolnisi_cross MEMBER mdi_bolnisi_cross CONSTANT)
    Q_PROPERTY(QString mdi_bolt MEMBER mdi_bolt CONSTANT)
    Q_PROPERTY(QString mdi_bomb MEMBER mdi_bomb CONSTANT)
    Q_PROPERTY(QString mdi_bomb_off MEMBER mdi_bomb_off CONSTANT)
    Q_PROPERTY(QString mdi_bone MEMBER mdi_bone CONSTANT)
    Q_PROPERTY(QString mdi_book MEMBER mdi_book CONSTANT)
    Q_PROPERTY(QString mdi_book_lock MEMBER mdi_book_lock CONSTANT)
    Q_PROPERTY(QString mdi_book_lock_open MEMBER mdi_book_lock_open CONSTANT)
    Q_PROPERTY(QString mdi_book_minus MEMBER mdi_book_minus CONSTANT)
    Q_PROPERTY(QString mdi_book_multiple MEMBER mdi_book_multiple CONSTANT)
    Q_PROPERTY(QString mdi_book_multiple_minus MEMBER mdi_book_multiple_minus CONSTANT)
    Q_PROPERTY(QString mdi_book_multiple_plus MEMBER mdi_book_multiple_plus CONSTANT)
    Q_PROPERTY(QString mdi_book_multiple_remove MEMBER mdi_book_multiple_remove CONSTANT)
    Q_PROPERTY(QString mdi_book_multiple_variant MEMBER mdi_book_multiple_variant CONSTANT)
    Q_PROPERTY(QString mdi_book_open MEMBER mdi_book_open CONSTANT)
    Q_PROPERTY(QString mdi_book_open_outline MEMBER mdi_book_open_outline CONSTANT)
    Q_PROPERTY(QString mdi_book_open_page_variant MEMBER mdi_book_open_page_variant CONSTANT)
    Q_PROPERTY(QString mdi_book_open_variant MEMBER mdi_book_open_variant CONSTANT)
    Q_PROPERTY(QString mdi_book_outline MEMBER mdi_book_outline CONSTANT)
    Q_PROPERTY(QString mdi_book_plus MEMBER mdi_book_plus CONSTANT)
    Q_PROPERTY(QString mdi_book_remove MEMBER mdi_book_remove CONSTANT)
    Q_PROPERTY(QString mdi_book_variant MEMBER mdi_book_variant CONSTANT)
    Q_PROPERTY(QString mdi_bookmark MEMBER mdi_bookmark CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_check MEMBER mdi_bookmark_check CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_minus MEMBER mdi_bookmark_minus CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_minus_outline MEMBER mdi_bookmark_minus_outline CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_music MEMBER mdi_bookmark_music CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_off MEMBER mdi_bookmark_off CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_off_outline MEMBER mdi_bookmark_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_outline MEMBER mdi_bookmark_outline CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_plus MEMBER mdi_bookmark_plus CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_plus_outline MEMBER mdi_bookmark_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_bookmark_remove MEMBER mdi_bookmark_remove CONSTANT)
    Q_PROPERTY(QString mdi_boombox MEMBER mdi_boombox CONSTANT)
    Q_PROPERTY(QString mdi_bootstrap MEMBER mdi_bootstrap CONSTANT)
    Q_PROPERTY(QString mdi_border_all MEMBER mdi_border_all CONSTANT)
    Q_PROPERTY(QString mdi_border_all_variant MEMBER mdi_border_all_variant CONSTANT)
    Q_PROPERTY(QString mdi_border_bottom MEMBER mdi_border_bottom CONSTANT)
    Q_PROPERTY(QString mdi_border_bottom_variant MEMBER mdi_border_bottom_variant CONSTANT)
    Q_PROPERTY(QString mdi_border_color MEMBER mdi_border_color CONSTANT)
    Q_PROPERTY(QString mdi_border_horizontal MEMBER mdi_border_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_border_inside MEMBER mdi_border_inside CONSTANT)
    Q_PROPERTY(QString mdi_border_left MEMBER mdi_border_left CONSTANT)
    Q_PROPERTY(QString mdi_border_left_variant MEMBER mdi_border_left_variant CONSTANT)
    Q_PROPERTY(QString mdi_border_none MEMBER mdi_border_none CONSTANT)
    Q_PROPERTY(QString mdi_border_none_variant MEMBER mdi_border_none_variant CONSTANT)
    Q_PROPERTY(QString mdi_border_outside MEMBER mdi_border_outside CONSTANT)
    Q_PROPERTY(QString mdi_border_right MEMBER mdi_border_right CONSTANT)
    Q_PROPERTY(QString mdi_border_right_variant MEMBER mdi_border_right_variant CONSTANT)
    Q_PROPERTY(QString mdi_border_style MEMBER mdi_border_style CONSTANT)
    Q_PROPERTY(QString mdi_border_top MEMBER mdi_border_top CONSTANT)
    Q_PROPERTY(QString mdi_border_top_variant MEMBER mdi_border_top_variant CONSTANT)
    Q_PROPERTY(QString mdi_border_vertical MEMBER mdi_border_vertical CONSTANT)
    Q_PROPERTY(QString mdi_bottle_wine MEMBER mdi_bottle_wine CONSTANT)
    Q_PROPERTY(QString mdi_bow_tie MEMBER mdi_bow_tie CONSTANT)
    Q_PROPERTY(QString mdi_bowl MEMBER mdi_bowl CONSTANT)
    Q_PROPERTY(QString mdi_bowling MEMBER mdi_bowling CONSTANT)
    Q_PROPERTY(QString mdi_box MEMBER mdi_box CONSTANT)
    Q_PROPERTY(QString mdi_box_cutter MEMBER mdi_box_cutter CONSTANT)
    Q_PROPERTY(QString mdi_box_shadow MEMBER mdi_box_shadow CONSTANT)
    Q_PROPERTY(QString mdi_boxing_glove MEMBER mdi_boxing_glove CONSTANT)
    Q_PROPERTY(QString mdi_braille MEMBER mdi_braille CONSTANT)
    Q_PROPERTY(QString mdi_brain MEMBER mdi_brain CONSTANT)
    Q_PROPERTY(QString mdi_bread_slice MEMBER mdi_bread_slice CONSTANT)
    Q_PROPERTY(QString mdi_bread_slice_outline MEMBER mdi_bread_slice_outline CONSTANT)
    Q_PROPERTY(QString mdi_bridge MEMBER mdi_bridge CONSTANT)
    Q_PROPERTY(QString mdi_briefcase MEMBER mdi_briefcase CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_account MEMBER mdi_briefcase_account CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_account_outline MEMBER mdi_briefcase_account_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_check MEMBER mdi_briefcase_check CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_download MEMBER mdi_briefcase_download CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_download_outline MEMBER mdi_briefcase_download_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_edit MEMBER mdi_briefcase_edit CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_edit_outline MEMBER mdi_briefcase_edit_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_minus MEMBER mdi_briefcase_minus CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_minus_outline MEMBER mdi_briefcase_minus_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_outline MEMBER mdi_briefcase_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_plus MEMBER mdi_briefcase_plus CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_plus_outline MEMBER mdi_briefcase_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_remove MEMBER mdi_briefcase_remove CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_remove_outline MEMBER mdi_briefcase_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_search MEMBER mdi_briefcase_search CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_search_outline MEMBER mdi_briefcase_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_upload MEMBER mdi_briefcase_upload CONSTANT)
    Q_PROPERTY(QString mdi_briefcase_upload_outline MEMBER mdi_briefcase_upload_outline CONSTANT)
    Q_PROPERTY(QString mdi_brightness_1 MEMBER mdi_brightness_1 CONSTANT)
    Q_PROPERTY(QString mdi_brightness_2 MEMBER mdi_brightness_2 CONSTANT)
    Q_PROPERTY(QString mdi_brightness_3 MEMBER mdi_brightness_3 CONSTANT)
    Q_PROPERTY(QString mdi_brightness_4 MEMBER mdi_brightness_4 CONSTANT)
    Q_PROPERTY(QString mdi_brightness_5 MEMBER mdi_brightness_5 CONSTANT)
    Q_PROPERTY(QString mdi_brightness_6 MEMBER mdi_brightness_6 CONSTANT)
    Q_PROPERTY(QString mdi_brightness_7 MEMBER mdi_brightness_7 CONSTANT)
    Q_PROPERTY(QString mdi_brightness_auto MEMBER mdi_brightness_auto CONSTANT)
    Q_PROPERTY(QString mdi_brightness_percent MEMBER mdi_brightness_percent CONSTANT)
    Q_PROPERTY(QString mdi_broom MEMBER mdi_broom CONSTANT)
    Q_PROPERTY(QString mdi_brush MEMBER mdi_brush CONSTANT)
    Q_PROPERTY(QString mdi_buddhism MEMBER mdi_buddhism CONSTANT)
    Q_PROPERTY(QString mdi_buffer MEMBER mdi_buffer CONSTANT)
    Q_PROPERTY(QString mdi_bug MEMBER mdi_bug CONSTANT)
    Q_PROPERTY(QString mdi_bug_check MEMBER mdi_bug_check CONSTANT)
    Q_PROPERTY(QString mdi_bug_check_outline MEMBER mdi_bug_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_bug_outline MEMBER mdi_bug_outline CONSTANT)
    Q_PROPERTY(QString mdi_bugle MEMBER mdi_bugle CONSTANT)
    Q_PROPERTY(QString mdi_bulldozer MEMBER mdi_bulldozer CONSTANT)
    Q_PROPERTY(QString mdi_bullet MEMBER mdi_bullet CONSTANT)
    Q_PROPERTY(QString mdi_bulletin_board MEMBER mdi_bulletin_board CONSTANT)
    Q_PROPERTY(QString mdi_bullhorn MEMBER mdi_bullhorn CONSTANT)
    Q_PROPERTY(QString mdi_bullhorn_outline MEMBER mdi_bullhorn_outline CONSTANT)
    Q_PROPERTY(QString mdi_bullseye MEMBER mdi_bullseye CONSTANT)
    Q_PROPERTY(QString mdi_bullseye_arrow MEMBER mdi_bullseye_arrow CONSTANT)
    Q_PROPERTY(QString mdi_bus MEMBER mdi_bus CONSTANT)
    Q_PROPERTY(QString mdi_bus_alert MEMBER mdi_bus_alert CONSTANT)
    Q_PROPERTY(QString mdi_bus_articulated_end MEMBER mdi_bus_articulated_end CONSTANT)
    Q_PROPERTY(QString mdi_bus_articulated_front MEMBER mdi_bus_articulated_front CONSTANT)
    Q_PROPERTY(QString mdi_bus_clock MEMBER mdi_bus_clock CONSTANT)
    Q_PROPERTY(QString mdi_bus_double_decker MEMBER mdi_bus_double_decker CONSTANT)
    Q_PROPERTY(QString mdi_bus_school MEMBER mdi_bus_school CONSTANT)
    Q_PROPERTY(QString mdi_bus_side MEMBER mdi_bus_side CONSTANT)
    Q_PROPERTY(QString mdi_cached MEMBER mdi_cached CONSTANT)
    Q_PROPERTY(QString mdi_cactus MEMBER mdi_cactus CONSTANT)
    Q_PROPERTY(QString mdi_cake MEMBER mdi_cake CONSTANT)
    Q_PROPERTY(QString mdi_cake_layered MEMBER mdi_cake_layered CONSTANT)
    Q_PROPERTY(QString mdi_cake_variant MEMBER mdi_cake_variant CONSTANT)
    Q_PROPERTY(QString mdi_calculator MEMBER mdi_calculator CONSTANT)
    Q_PROPERTY(QString mdi_calculator_variant MEMBER mdi_calculator_variant CONSTANT)
    Q_PROPERTY(QString mdi_calendar MEMBER mdi_calendar CONSTANT)
    Q_PROPERTY(QString mdi_calendar_alert MEMBER mdi_calendar_alert CONSTANT)
    Q_PROPERTY(QString mdi_calendar_blank MEMBER mdi_calendar_blank CONSTANT)
    Q_PROPERTY(QString mdi_calendar_blank_outline MEMBER mdi_calendar_blank_outline CONSTANT)
    Q_PROPERTY(QString mdi_calendar_check MEMBER mdi_calendar_check CONSTANT)
    Q_PROPERTY(QString mdi_calendar_check_outline MEMBER mdi_calendar_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_calendar_clock MEMBER mdi_calendar_clock CONSTANT)
    Q_PROPERTY(QString mdi_calendar_edit MEMBER mdi_calendar_edit CONSTANT)
    Q_PROPERTY(QString mdi_calendar_export MEMBER mdi_calendar_export CONSTANT)
    Q_PROPERTY(QString mdi_calendar_heart MEMBER mdi_calendar_heart CONSTANT)
    Q_PROPERTY(QString mdi_calendar_import MEMBER mdi_calendar_import CONSTANT)
    Q_PROPERTY(QString mdi_calendar_minus MEMBER mdi_calendar_minus CONSTANT)
    Q_PROPERTY(QString mdi_calendar_multiple MEMBER mdi_calendar_multiple CONSTANT)
    Q_PROPERTY(QString mdi_calendar_multiple_check MEMBER mdi_calendar_multiple_check CONSTANT)
    Q_PROPERTY(QString mdi_calendar_multiselect MEMBER mdi_calendar_multiselect CONSTANT)
    Q_PROPERTY(QString mdi_calendar_outline MEMBER mdi_calendar_outline CONSTANT)
    Q_PROPERTY(QString mdi_calendar_plus MEMBER mdi_calendar_plus CONSTANT)
    Q_PROPERTY(QString mdi_calendar_question MEMBER mdi_calendar_question CONSTANT)
    Q_PROPERTY(QString mdi_calendar_range MEMBER mdi_calendar_range CONSTANT)
    Q_PROPERTY(QString mdi_calendar_range_outline MEMBER mdi_calendar_range_outline CONSTANT)
    Q_PROPERTY(QString mdi_calendar_remove MEMBER mdi_calendar_remove CONSTANT)
    Q_PROPERTY(QString mdi_calendar_remove_outline MEMBER mdi_calendar_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_calendar_search MEMBER mdi_calendar_search CONSTANT)
    Q_PROPERTY(QString mdi_calendar_star MEMBER mdi_calendar_star CONSTANT)
    Q_PROPERTY(QString mdi_calendar_text MEMBER mdi_calendar_text CONSTANT)
    Q_PROPERTY(QString mdi_calendar_text_outline MEMBER mdi_calendar_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_calendar_today MEMBER mdi_calendar_today CONSTANT)
    Q_PROPERTY(QString mdi_calendar_week MEMBER mdi_calendar_week CONSTANT)
    Q_PROPERTY(QString mdi_calendar_week_begin MEMBER mdi_calendar_week_begin CONSTANT)
    Q_PROPERTY(QString mdi_call_made MEMBER mdi_call_made CONSTANT)
    Q_PROPERTY(QString mdi_call_merge MEMBER mdi_call_merge CONSTANT)
    Q_PROPERTY(QString mdi_call_missed MEMBER mdi_call_missed CONSTANT)
    Q_PROPERTY(QString mdi_call_received MEMBER mdi_call_received CONSTANT)
    Q_PROPERTY(QString mdi_call_split MEMBER mdi_call_split CONSTANT)
    Q_PROPERTY(QString mdi_camcorder MEMBER mdi_camcorder CONSTANT)
    Q_PROPERTY(QString mdi_camcorder_box MEMBER mdi_camcorder_box CONSTANT)
    Q_PROPERTY(QString mdi_camcorder_box_off MEMBER mdi_camcorder_box_off CONSTANT)
    Q_PROPERTY(QString mdi_camcorder_off MEMBER mdi_camcorder_off CONSTANT)
    Q_PROPERTY(QString mdi_camera MEMBER mdi_camera CONSTANT)
    Q_PROPERTY(QString mdi_camera_account MEMBER mdi_camera_account CONSTANT)
    Q_PROPERTY(QString mdi_camera_burst MEMBER mdi_camera_burst CONSTANT)
    Q_PROPERTY(QString mdi_camera_control MEMBER mdi_camera_control CONSTANT)
    Q_PROPERTY(QString mdi_camera_enhance MEMBER mdi_camera_enhance CONSTANT)
    Q_PROPERTY(QString mdi_camera_enhance_outline MEMBER mdi_camera_enhance_outline CONSTANT)
    Q_PROPERTY(QString mdi_camera_front MEMBER mdi_camera_front CONSTANT)
    Q_PROPERTY(QString mdi_camera_front_variant MEMBER mdi_camera_front_variant CONSTANT)
    Q_PROPERTY(QString mdi_camera_gopro MEMBER mdi_camera_gopro CONSTANT)
    Q_PROPERTY(QString mdi_camera_image MEMBER mdi_camera_image CONSTANT)
    Q_PROPERTY(QString mdi_camera_iris MEMBER mdi_camera_iris CONSTANT)
    Q_PROPERTY(QString mdi_camera_metering_center MEMBER mdi_camera_metering_center CONSTANT)
    Q_PROPERTY(QString mdi_camera_metering_matrix MEMBER mdi_camera_metering_matrix CONSTANT)
    Q_PROPERTY(QString mdi_camera_metering_partial MEMBER mdi_camera_metering_partial CONSTANT)
    Q_PROPERTY(QString mdi_camera_metering_spot MEMBER mdi_camera_metering_spot CONSTANT)
    Q_PROPERTY(QString mdi_camera_off MEMBER mdi_camera_off CONSTANT)
    Q_PROPERTY(QString mdi_camera_outline MEMBER mdi_camera_outline CONSTANT)
    Q_PROPERTY(QString mdi_camera_party_mode MEMBER mdi_camera_party_mode CONSTANT)
    Q_PROPERTY(QString mdi_camera_rear MEMBER mdi_camera_rear CONSTANT)
    Q_PROPERTY(QString mdi_camera_rear_variant MEMBER mdi_camera_rear_variant CONSTANT)
    Q_PROPERTY(QString mdi_camera_switch MEMBER mdi_camera_switch CONSTANT)
    Q_PROPERTY(QString mdi_camera_timer MEMBER mdi_camera_timer CONSTANT)
    Q_PROPERTY(QString mdi_camera_wireless MEMBER mdi_camera_wireless CONSTANT)
    Q_PROPERTY(QString mdi_camera_wireless_outline MEMBER mdi_camera_wireless_outline CONSTANT)
    Q_PROPERTY(QString mdi_cancel MEMBER mdi_cancel CONSTANT)
    Q_PROPERTY(QString mdi_candle MEMBER mdi_candle CONSTANT)
    Q_PROPERTY(QString mdi_candycane MEMBER mdi_candycane CONSTANT)
//    Q_PROPERTY(QString mdi_cannabis MEMBER mdi_cannabis CONSTANT)
    Q_PROPERTY(QString mdi_caps_lock MEMBER mdi_caps_lock CONSTANT)
    Q_PROPERTY(QString mdi_car MEMBER mdi_car CONSTANT)
    Q_PROPERTY(QString mdi_car_battery MEMBER mdi_car_battery CONSTANT)
    Q_PROPERTY(QString mdi_car_brake_abs MEMBER mdi_car_brake_abs CONSTANT)
    Q_PROPERTY(QString mdi_car_brake_alert MEMBER mdi_car_brake_alert CONSTANT)
    Q_PROPERTY(QString mdi_car_brake_hold MEMBER mdi_car_brake_hold CONSTANT)
    Q_PROPERTY(QString mdi_car_brake_parking MEMBER mdi_car_brake_parking CONSTANT)
    Q_PROPERTY(QString mdi_car_connected MEMBER mdi_car_connected CONSTANT)
    Q_PROPERTY(QString mdi_car_convertible MEMBER mdi_car_convertible CONSTANT)
    Q_PROPERTY(QString mdi_car_cruise_control MEMBER mdi_car_cruise_control CONSTANT)
    Q_PROPERTY(QString mdi_car_defrost_front MEMBER mdi_car_defrost_front CONSTANT)
    Q_PROPERTY(QString mdi_car_defrost_rear MEMBER mdi_car_defrost_rear CONSTANT)
    Q_PROPERTY(QString mdi_car_door MEMBER mdi_car_door CONSTANT)
    Q_PROPERTY(QString mdi_car_electric MEMBER mdi_car_electric CONSTANT)
    Q_PROPERTY(QString mdi_car_esp MEMBER mdi_car_esp CONSTANT)
    Q_PROPERTY(QString mdi_car_estate MEMBER mdi_car_estate CONSTANT)
    Q_PROPERTY(QString mdi_car_hatchback MEMBER mdi_car_hatchback CONSTANT)
    Q_PROPERTY(QString mdi_car_key MEMBER mdi_car_key CONSTANT)
    Q_PROPERTY(QString mdi_car_light_dimmed MEMBER mdi_car_light_dimmed CONSTANT)
    Q_PROPERTY(QString mdi_car_light_fog MEMBER mdi_car_light_fog CONSTANT)
    Q_PROPERTY(QString mdi_car_light_high MEMBER mdi_car_light_high CONSTANT)
    Q_PROPERTY(QString mdi_car_limousine MEMBER mdi_car_limousine CONSTANT)
    Q_PROPERTY(QString mdi_car_multiple MEMBER mdi_car_multiple CONSTANT)
    Q_PROPERTY(QString mdi_car_parking_lights MEMBER mdi_car_parking_lights CONSTANT)
    Q_PROPERTY(QString mdi_car_pickup MEMBER mdi_car_pickup CONSTANT)
    Q_PROPERTY(QString mdi_car_side MEMBER mdi_car_side CONSTANT)
    Q_PROPERTY(QString mdi_car_sports MEMBER mdi_car_sports CONSTANT)
    Q_PROPERTY(QString mdi_car_tire_alert MEMBER mdi_car_tire_alert CONSTANT)
    Q_PROPERTY(QString mdi_car_traction_control MEMBER mdi_car_traction_control CONSTANT)
    Q_PROPERTY(QString mdi_car_wash MEMBER mdi_car_wash CONSTANT)
    Q_PROPERTY(QString mdi_caravan MEMBER mdi_caravan CONSTANT)
    Q_PROPERTY(QString mdi_card MEMBER mdi_card CONSTANT)
    Q_PROPERTY(QString mdi_card_bulleted MEMBER mdi_card_bulleted CONSTANT)
    Q_PROPERTY(QString mdi_card_bulleted_off MEMBER mdi_card_bulleted_off CONSTANT)
    Q_PROPERTY(QString mdi_card_bulleted_off_outline MEMBER mdi_card_bulleted_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_card_bulleted_outline MEMBER mdi_card_bulleted_outline CONSTANT)
    Q_PROPERTY(QString mdi_card_bulleted_settings MEMBER mdi_card_bulleted_settings CONSTANT)
    Q_PROPERTY(QString mdi_card_bulleted_settings_outline MEMBER mdi_card_bulleted_settings_outline CONSTANT)
    Q_PROPERTY(QString mdi_card_outline MEMBER mdi_card_outline CONSTANT)
    Q_PROPERTY(QString mdi_card_text MEMBER mdi_card_text CONSTANT)
    Q_PROPERTY(QString mdi_card_text_outline MEMBER mdi_card_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_cards MEMBER mdi_cards CONSTANT)
    Q_PROPERTY(QString mdi_cards_club MEMBER mdi_cards_club CONSTANT)
    Q_PROPERTY(QString mdi_cards_diamond MEMBER mdi_cards_diamond CONSTANT)
    Q_PROPERTY(QString mdi_cards_heart MEMBER mdi_cards_heart CONSTANT)
    Q_PROPERTY(QString mdi_cards_outline MEMBER mdi_cards_outline CONSTANT)
    Q_PROPERTY(QString mdi_cards_playing_outline MEMBER mdi_cards_playing_outline CONSTANT)
    Q_PROPERTY(QString mdi_cards_spade MEMBER mdi_cards_spade CONSTANT)
    Q_PROPERTY(QString mdi_cards_variant MEMBER mdi_cards_variant CONSTANT)
    Q_PROPERTY(QString mdi_carrot MEMBER mdi_carrot CONSTANT)
    Q_PROPERTY(QString mdi_carry_on_bag_check MEMBER mdi_carry_on_bag_check CONSTANT)
    Q_PROPERTY(QString mdi_cart MEMBER mdi_cart CONSTANT)
    Q_PROPERTY(QString mdi_cart_arrow_down MEMBER mdi_cart_arrow_down CONSTANT)
    Q_PROPERTY(QString mdi_cart_arrow_right MEMBER mdi_cart_arrow_right CONSTANT)
    Q_PROPERTY(QString mdi_cart_arrow_up MEMBER mdi_cart_arrow_up CONSTANT)
    Q_PROPERTY(QString mdi_cart_minus MEMBER mdi_cart_minus CONSTANT)
    Q_PROPERTY(QString mdi_cart_off MEMBER mdi_cart_off CONSTANT)
    Q_PROPERTY(QString mdi_cart_outline MEMBER mdi_cart_outline CONSTANT)
    Q_PROPERTY(QString mdi_cart_plus MEMBER mdi_cart_plus CONSTANT)
    Q_PROPERTY(QString mdi_cart_remove MEMBER mdi_cart_remove CONSTANT)
    Q_PROPERTY(QString mdi_case_sensitive_alt MEMBER mdi_case_sensitive_alt CONSTANT)
    Q_PROPERTY(QString mdi_cash MEMBER mdi_cash CONSTANT)
    Q_PROPERTY(QString mdi_cash_100 MEMBER mdi_cash_100 CONSTANT)
    Q_PROPERTY(QString mdi_cash_marker MEMBER mdi_cash_marker CONSTANT)
    Q_PROPERTY(QString mdi_cash_multiple MEMBER mdi_cash_multiple CONSTANT)
    Q_PROPERTY(QString mdi_cash_refund MEMBER mdi_cash_refund CONSTANT)
    Q_PROPERTY(QString mdi_cash_register MEMBER mdi_cash_register CONSTANT)
    Q_PROPERTY(QString mdi_cash_usd MEMBER mdi_cash_usd CONSTANT)
    Q_PROPERTY(QString mdi_cassette MEMBER mdi_cassette CONSTANT)
    Q_PROPERTY(QString mdi_cast MEMBER mdi_cast CONSTANT)
    Q_PROPERTY(QString mdi_cast_connected MEMBER mdi_cast_connected CONSTANT)
    Q_PROPERTY(QString mdi_cast_off MEMBER mdi_cast_off CONSTANT)
    Q_PROPERTY(QString mdi_castle MEMBER mdi_castle CONSTANT)
    Q_PROPERTY(QString mdi_cat MEMBER mdi_cat CONSTANT)
    Q_PROPERTY(QString mdi_cctv MEMBER mdi_cctv CONSTANT)
    Q_PROPERTY(QString mdi_ceiling_light MEMBER mdi_ceiling_light CONSTANT)
    Q_PROPERTY(QString mdi_cellphone MEMBER mdi_cellphone CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_android MEMBER mdi_cellphone_android CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_arrow_down MEMBER mdi_cellphone_arrow_down CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_basic MEMBER mdi_cellphone_basic CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_dock MEMBER mdi_cellphone_dock CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_erase MEMBER mdi_cellphone_erase CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_iphone MEMBER mdi_cellphone_iphone CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_key MEMBER mdi_cellphone_key CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_link MEMBER mdi_cellphone_link CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_link_off MEMBER mdi_cellphone_link_off CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_lock MEMBER mdi_cellphone_lock CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_message MEMBER mdi_cellphone_message CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_off MEMBER mdi_cellphone_off CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_screenshot MEMBER mdi_cellphone_screenshot CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_settings MEMBER mdi_cellphone_settings CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_settings_variant MEMBER mdi_cellphone_settings_variant CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_sound MEMBER mdi_cellphone_sound CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_text MEMBER mdi_cellphone_text CONSTANT)
    Q_PROPERTY(QString mdi_cellphone_wireless MEMBER mdi_cellphone_wireless CONSTANT)
    Q_PROPERTY(QString mdi_celtic_cross MEMBER mdi_celtic_cross CONSTANT)
    Q_PROPERTY(QString mdi_certificate MEMBER mdi_certificate CONSTANT)
    Q_PROPERTY(QString mdi_chair_school MEMBER mdi_chair_school CONSTANT)
    Q_PROPERTY(QString mdi_charity MEMBER mdi_charity CONSTANT)
    Q_PROPERTY(QString mdi_chart_arc MEMBER mdi_chart_arc CONSTANT)
    Q_PROPERTY(QString mdi_chart_areaspline MEMBER mdi_chart_areaspline CONSTANT)
    Q_PROPERTY(QString mdi_chart_bar MEMBER mdi_chart_bar CONSTANT)
    Q_PROPERTY(QString mdi_chart_bar_stacked MEMBER mdi_chart_bar_stacked CONSTANT)
    Q_PROPERTY(QString mdi_chart_bell_curve MEMBER mdi_chart_bell_curve CONSTANT)
    Q_PROPERTY(QString mdi_chart_bubble MEMBER mdi_chart_bubble CONSTANT)
    Q_PROPERTY(QString mdi_chart_donut MEMBER mdi_chart_donut CONSTANT)
    Q_PROPERTY(QString mdi_chart_donut_variant MEMBER mdi_chart_donut_variant CONSTANT)
    Q_PROPERTY(QString mdi_chart_gantt MEMBER mdi_chart_gantt CONSTANT)
    Q_PROPERTY(QString mdi_chart_histogram MEMBER mdi_chart_histogram CONSTANT)
    Q_PROPERTY(QString mdi_chart_line MEMBER mdi_chart_line CONSTANT)
    Q_PROPERTY(QString mdi_chart_line_stacked MEMBER mdi_chart_line_stacked CONSTANT)
    Q_PROPERTY(QString mdi_chart_line_variant MEMBER mdi_chart_line_variant CONSTANT)
    Q_PROPERTY(QString mdi_chart_multiline MEMBER mdi_chart_multiline CONSTANT)
    Q_PROPERTY(QString mdi_chart_pie MEMBER mdi_chart_pie CONSTANT)
    Q_PROPERTY(QString mdi_chart_scatterplot_hexbin MEMBER mdi_chart_scatterplot_hexbin CONSTANT)
    Q_PROPERTY(QString mdi_chart_timeline MEMBER mdi_chart_timeline CONSTANT)
    Q_PROPERTY(QString mdi_chat MEMBER mdi_chat CONSTANT)
    Q_PROPERTY(QString mdi_chat_alert MEMBER mdi_chat_alert CONSTANT)
    Q_PROPERTY(QString mdi_chat_processing MEMBER mdi_chat_processing CONSTANT)
    Q_PROPERTY(QString mdi_check MEMBER mdi_check CONSTANT)
    Q_PROPERTY(QString mdi_check_all MEMBER mdi_check_all CONSTANT)
    Q_PROPERTY(QString mdi_check_box_multiple_outline MEMBER mdi_check_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_check_box_outline MEMBER mdi_check_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_check_circle MEMBER mdi_check_circle CONSTANT)
    Q_PROPERTY(QString mdi_check_circle_outline MEMBER mdi_check_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_check_decagram MEMBER mdi_check_decagram CONSTANT)
    Q_PROPERTY(QString mdi_check_network MEMBER mdi_check_network CONSTANT)
    Q_PROPERTY(QString mdi_check_network_outline MEMBER mdi_check_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_check_outline MEMBER mdi_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbook MEMBER mdi_checkbook CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_blank MEMBER mdi_checkbox_blank CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_blank_circle MEMBER mdi_checkbox_blank_circle CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_blank_circle_outline MEMBER mdi_checkbox_blank_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_blank_outline MEMBER mdi_checkbox_blank_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_intermediate MEMBER mdi_checkbox_intermediate CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_marked MEMBER mdi_checkbox_marked CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_marked_circle MEMBER mdi_checkbox_marked_circle CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_marked_circle_outline MEMBER mdi_checkbox_marked_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_marked_outline MEMBER mdi_checkbox_marked_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_blank MEMBER mdi_checkbox_multiple_blank CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_blank_circle MEMBER mdi_checkbox_multiple_blank_circle CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_blank_circle_outline MEMBER mdi_checkbox_multiple_blank_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_blank_outline MEMBER mdi_checkbox_multiple_blank_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_marked MEMBER mdi_checkbox_multiple_marked CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_marked_circle MEMBER mdi_checkbox_multiple_marked_circle CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_marked_circle_outline MEMBER mdi_checkbox_multiple_marked_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkbox_multiple_marked_outline MEMBER mdi_checkbox_multiple_marked_outline CONSTANT)
    Q_PROPERTY(QString mdi_checkerboard MEMBER mdi_checkerboard CONSTANT)
    Q_PROPERTY(QString mdi_chef_hat MEMBER mdi_chef_hat CONSTANT)
    Q_PROPERTY(QString mdi_chemical_weapon MEMBER mdi_chemical_weapon CONSTANT)
    Q_PROPERTY(QString mdi_chess_bishop MEMBER mdi_chess_bishop CONSTANT)
    Q_PROPERTY(QString mdi_chess_king MEMBER mdi_chess_king CONSTANT)
    Q_PROPERTY(QString mdi_chess_knight MEMBER mdi_chess_knight CONSTANT)
    Q_PROPERTY(QString mdi_chess_pawn MEMBER mdi_chess_pawn CONSTANT)
    Q_PROPERTY(QString mdi_chess_queen MEMBER mdi_chess_queen CONSTANT)
    Q_PROPERTY(QString mdi_chess_rook MEMBER mdi_chess_rook CONSTANT)
    Q_PROPERTY(QString mdi_chevron_double_down MEMBER mdi_chevron_double_down CONSTANT)
    Q_PROPERTY(QString mdi_chevron_double_left MEMBER mdi_chevron_double_left CONSTANT)
    Q_PROPERTY(QString mdi_chevron_double_right MEMBER mdi_chevron_double_right CONSTANT)
    Q_PROPERTY(QString mdi_chevron_double_up MEMBER mdi_chevron_double_up CONSTANT)
    Q_PROPERTY(QString mdi_chevron_down MEMBER mdi_chevron_down CONSTANT)
    Q_PROPERTY(QString mdi_chevron_down_box MEMBER mdi_chevron_down_box CONSTANT)
    Q_PROPERTY(QString mdi_chevron_down_box_outline MEMBER mdi_chevron_down_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_chevron_down_circle MEMBER mdi_chevron_down_circle CONSTANT)
    Q_PROPERTY(QString mdi_chevron_down_circle_outline MEMBER mdi_chevron_down_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_chevron_left MEMBER mdi_chevron_left CONSTANT)
    Q_PROPERTY(QString mdi_chevron_left_box MEMBER mdi_chevron_left_box CONSTANT)
    Q_PROPERTY(QString mdi_chevron_left_box_outline MEMBER mdi_chevron_left_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_chevron_left_circle MEMBER mdi_chevron_left_circle CONSTANT)
    Q_PROPERTY(QString mdi_chevron_left_circle_outline MEMBER mdi_chevron_left_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_chevron_right MEMBER mdi_chevron_right CONSTANT)
    Q_PROPERTY(QString mdi_chevron_right_box MEMBER mdi_chevron_right_box CONSTANT)
    Q_PROPERTY(QString mdi_chevron_right_box_outline MEMBER mdi_chevron_right_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_chevron_right_circle MEMBER mdi_chevron_right_circle CONSTANT)
    Q_PROPERTY(QString mdi_chevron_right_circle_outline MEMBER mdi_chevron_right_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_chevron_triple_down MEMBER mdi_chevron_triple_down CONSTANT)
    Q_PROPERTY(QString mdi_chevron_triple_left MEMBER mdi_chevron_triple_left CONSTANT)
    Q_PROPERTY(QString mdi_chevron_triple_right MEMBER mdi_chevron_triple_right CONSTANT)
    Q_PROPERTY(QString mdi_chevron_triple_up MEMBER mdi_chevron_triple_up CONSTANT)
    Q_PROPERTY(QString mdi_chevron_up MEMBER mdi_chevron_up CONSTANT)
    Q_PROPERTY(QString mdi_chevron_up_box MEMBER mdi_chevron_up_box CONSTANT)
    Q_PROPERTY(QString mdi_chevron_up_box_outline MEMBER mdi_chevron_up_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_chevron_up_circle MEMBER mdi_chevron_up_circle CONSTANT)
    Q_PROPERTY(QString mdi_chevron_up_circle_outline MEMBER mdi_chevron_up_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_chili_hot MEMBER mdi_chili_hot CONSTANT)
    Q_PROPERTY(QString mdi_chili_medium MEMBER mdi_chili_medium CONSTANT)
    Q_PROPERTY(QString mdi_chili_mild MEMBER mdi_chili_mild CONSTANT)
    Q_PROPERTY(QString mdi_chip MEMBER mdi_chip CONSTANT)
    Q_PROPERTY(QString mdi_christianity MEMBER mdi_christianity CONSTANT)
    Q_PROPERTY(QString mdi_christianity_outline MEMBER mdi_christianity_outline CONSTANT)
    Q_PROPERTY(QString mdi_church MEMBER mdi_church CONSTANT)
    Q_PROPERTY(QString mdi_circle MEMBER mdi_circle CONSTANT)
    Q_PROPERTY(QString mdi_circle_edit_outline MEMBER mdi_circle_edit_outline CONSTANT)
    Q_PROPERTY(QString mdi_circle_medium MEMBER mdi_circle_medium CONSTANT)
    Q_PROPERTY(QString mdi_circle_outline MEMBER mdi_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_1 MEMBER mdi_circle_slice_1 CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_2 MEMBER mdi_circle_slice_2 CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_3 MEMBER mdi_circle_slice_3 CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_4 MEMBER mdi_circle_slice_4 CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_5 MEMBER mdi_circle_slice_5 CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_6 MEMBER mdi_circle_slice_6 CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_7 MEMBER mdi_circle_slice_7 CONSTANT)
    Q_PROPERTY(QString mdi_circle_slice_8 MEMBER mdi_circle_slice_8 CONSTANT)
    Q_PROPERTY(QString mdi_circle_small MEMBER mdi_circle_small CONSTANT)
    Q_PROPERTY(QString mdi_cisco_webex MEMBER mdi_cisco_webex CONSTANT)
    Q_PROPERTY(QString mdi_city MEMBER mdi_city CONSTANT)
    Q_PROPERTY(QString mdi_city_variant MEMBER mdi_city_variant CONSTANT)
    Q_PROPERTY(QString mdi_city_variant_outline MEMBER mdi_city_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard MEMBER mdi_clipboard CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_account MEMBER mdi_clipboard_account CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_account_outline MEMBER mdi_clipboard_account_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_alert MEMBER mdi_clipboard_alert CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_alert_outline MEMBER mdi_clipboard_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_down MEMBER mdi_clipboard_arrow_down CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_down_outline MEMBER mdi_clipboard_arrow_down_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_left MEMBER mdi_clipboard_arrow_left CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_left_outline MEMBER mdi_clipboard_arrow_left_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_right MEMBER mdi_clipboard_arrow_right CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_right_outline MEMBER mdi_clipboard_arrow_right_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_up MEMBER mdi_clipboard_arrow_up CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_arrow_up_outline MEMBER mdi_clipboard_arrow_up_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_check MEMBER mdi_clipboard_check CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_check_outline MEMBER mdi_clipboard_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_flow MEMBER mdi_clipboard_flow CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_outline MEMBER mdi_clipboard_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_play MEMBER mdi_clipboard_play CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_play_outline MEMBER mdi_clipboard_play_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_plus MEMBER mdi_clipboard_plus CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_pulse MEMBER mdi_clipboard_pulse CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_pulse_outline MEMBER mdi_clipboard_pulse_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_text MEMBER mdi_clipboard_text CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_text_outline MEMBER mdi_clipboard_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_text_play MEMBER mdi_clipboard_text_play CONSTANT)
    Q_PROPERTY(QString mdi_clipboard_text_play_outline MEMBER mdi_clipboard_text_play_outline CONSTANT)
    Q_PROPERTY(QString mdi_clippy MEMBER mdi_clippy CONSTANT)
    Q_PROPERTY(QString mdi_clock MEMBER mdi_clock CONSTANT)
    Q_PROPERTY(QString mdi_clock_alert MEMBER mdi_clock_alert CONSTANT)
    Q_PROPERTY(QString mdi_clock_alert_outline MEMBER mdi_clock_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_clock_end MEMBER mdi_clock_end CONSTANT)
    Q_PROPERTY(QString mdi_clock_fast MEMBER mdi_clock_fast CONSTANT)
    Q_PROPERTY(QString mdi_clock_in MEMBER mdi_clock_in CONSTANT)
    Q_PROPERTY(QString mdi_clock_out MEMBER mdi_clock_out CONSTANT)
//    Q_PROPERTY(QString mdi_clock_outline MEMBER mdi_clock_outline CONSTANT)
    Q_PROPERTY(QString mdi_clock_start MEMBER mdi_clock_start CONSTANT)
    Q_PROPERTY(QString mdi_close MEMBER mdi_close CONSTANT)
    Q_PROPERTY(QString mdi_close_box MEMBER mdi_close_box CONSTANT)
    Q_PROPERTY(QString mdi_close_box_multiple MEMBER mdi_close_box_multiple CONSTANT)
    Q_PROPERTY(QString mdi_close_box_multiple_outline MEMBER mdi_close_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_close_box_outline MEMBER mdi_close_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_close_circle MEMBER mdi_close_circle CONSTANT)
    Q_PROPERTY(QString mdi_close_circle_outline MEMBER mdi_close_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_close_network MEMBER mdi_close_network CONSTANT)
    Q_PROPERTY(QString mdi_close_network_outline MEMBER mdi_close_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_close_octagon MEMBER mdi_close_octagon CONSTANT)
    Q_PROPERTY(QString mdi_close_octagon_outline MEMBER mdi_close_octagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_close_outline MEMBER mdi_close_outline CONSTANT)
    Q_PROPERTY(QString mdi_closed_caption MEMBER mdi_closed_caption CONSTANT)
    Q_PROPERTY(QString mdi_closed_caption_outline MEMBER mdi_closed_caption_outline CONSTANT)
    Q_PROPERTY(QString mdi_cloud MEMBER mdi_cloud CONSTANT)
    Q_PROPERTY(QString mdi_cloud_alert MEMBER mdi_cloud_alert CONSTANT)
    Q_PROPERTY(QString mdi_cloud_braces MEMBER mdi_cloud_braces CONSTANT)
    Q_PROPERTY(QString mdi_cloud_check MEMBER mdi_cloud_check CONSTANT)
    Q_PROPERTY(QString mdi_cloud_circle MEMBER mdi_cloud_circle CONSTANT)
    Q_PROPERTY(QString mdi_cloud_download MEMBER mdi_cloud_download CONSTANT)
    Q_PROPERTY(QString mdi_cloud_download_outline MEMBER mdi_cloud_download_outline CONSTANT)
    Q_PROPERTY(QString mdi_cloud_off_outline MEMBER mdi_cloud_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_cloud_outline MEMBER mdi_cloud_outline CONSTANT)
    Q_PROPERTY(QString mdi_cloud_print MEMBER mdi_cloud_print CONSTANT)
    Q_PROPERTY(QString mdi_cloud_print_outline MEMBER mdi_cloud_print_outline CONSTANT)
    Q_PROPERTY(QString mdi_cloud_question MEMBER mdi_cloud_question CONSTANT)
    Q_PROPERTY(QString mdi_cloud_search MEMBER mdi_cloud_search CONSTANT)
    Q_PROPERTY(QString mdi_cloud_search_outline MEMBER mdi_cloud_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_cloud_sync MEMBER mdi_cloud_sync CONSTANT)
    Q_PROPERTY(QString mdi_cloud_tags MEMBER mdi_cloud_tags CONSTANT)
    Q_PROPERTY(QString mdi_cloud_upload MEMBER mdi_cloud_upload CONSTANT)
    Q_PROPERTY(QString mdi_cloud_upload_outline MEMBER mdi_cloud_upload_outline CONSTANT)
    Q_PROPERTY(QString mdi_clover MEMBER mdi_clover CONSTANT)
    Q_PROPERTY(QString mdi_code_array MEMBER mdi_code_array CONSTANT)
    Q_PROPERTY(QString mdi_code_braces MEMBER mdi_code_braces CONSTANT)
    Q_PROPERTY(QString mdi_code_brackets MEMBER mdi_code_brackets CONSTANT)
    Q_PROPERTY(QString mdi_code_equal MEMBER mdi_code_equal CONSTANT)
    Q_PROPERTY(QString mdi_code_greater_than MEMBER mdi_code_greater_than CONSTANT)
    Q_PROPERTY(QString mdi_code_greater_than_or_equal MEMBER mdi_code_greater_than_or_equal CONSTANT)
    Q_PROPERTY(QString mdi_code_less_than MEMBER mdi_code_less_than CONSTANT)
    Q_PROPERTY(QString mdi_code_less_than_or_equal MEMBER mdi_code_less_than_or_equal CONSTANT)
    Q_PROPERTY(QString mdi_code_not_equal MEMBER mdi_code_not_equal CONSTANT)
    Q_PROPERTY(QString mdi_code_not_equal_variant MEMBER mdi_code_not_equal_variant CONSTANT)
    Q_PROPERTY(QString mdi_code_parentheses MEMBER mdi_code_parentheses CONSTANT)
    Q_PROPERTY(QString mdi_code_string MEMBER mdi_code_string CONSTANT)
    Q_PROPERTY(QString mdi_code_tags MEMBER mdi_code_tags CONSTANT)
    Q_PROPERTY(QString mdi_code_tags_check MEMBER mdi_code_tags_check CONSTANT)
    Q_PROPERTY(QString mdi_codepen MEMBER mdi_codepen CONSTANT)
    Q_PROPERTY(QString mdi_coffee MEMBER mdi_coffee CONSTANT)
    Q_PROPERTY(QString mdi_coffee_outline MEMBER mdi_coffee_outline CONSTANT)
    Q_PROPERTY(QString mdi_coffee_to_go MEMBER mdi_coffee_to_go CONSTANT)
    Q_PROPERTY(QString mdi_coffin MEMBER mdi_coffin CONSTANT)
    Q_PROPERTY(QString mdi_cogs MEMBER mdi_cogs CONSTANT)
    Q_PROPERTY(QString mdi_coin MEMBER mdi_coin CONSTANT)
    Q_PROPERTY(QString mdi_coins MEMBER mdi_coins CONSTANT)
    Q_PROPERTY(QString mdi_collage MEMBER mdi_collage CONSTANT)
    Q_PROPERTY(QString mdi_collapse_all MEMBER mdi_collapse_all CONSTANT)
    Q_PROPERTY(QString mdi_collapse_all_outline MEMBER mdi_collapse_all_outline CONSTANT)
    Q_PROPERTY(QString mdi_color_helper MEMBER mdi_color_helper CONSTANT)
    Q_PROPERTY(QString mdi_comment MEMBER mdi_comment CONSTANT)
    Q_PROPERTY(QString mdi_comment_account MEMBER mdi_comment_account CONSTANT)
    Q_PROPERTY(QString mdi_comment_account_outline MEMBER mdi_comment_account_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_alert MEMBER mdi_comment_alert CONSTANT)
    Q_PROPERTY(QString mdi_comment_alert_outline MEMBER mdi_comment_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_arrow_left MEMBER mdi_comment_arrow_left CONSTANT)
    Q_PROPERTY(QString mdi_comment_arrow_left_outline MEMBER mdi_comment_arrow_left_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_arrow_right MEMBER mdi_comment_arrow_right CONSTANT)
    Q_PROPERTY(QString mdi_comment_arrow_right_outline MEMBER mdi_comment_arrow_right_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_check MEMBER mdi_comment_check CONSTANT)
    Q_PROPERTY(QString mdi_comment_check_outline MEMBER mdi_comment_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_eye MEMBER mdi_comment_eye CONSTANT)
    Q_PROPERTY(QString mdi_comment_eye_outline MEMBER mdi_comment_eye_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_multiple MEMBER mdi_comment_multiple CONSTANT)
    Q_PROPERTY(QString mdi_comment_multiple_outline MEMBER mdi_comment_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_outline MEMBER mdi_comment_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_plus MEMBER mdi_comment_plus CONSTANT)
    Q_PROPERTY(QString mdi_comment_plus_outline MEMBER mdi_comment_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_processing MEMBER mdi_comment_processing CONSTANT)
    Q_PROPERTY(QString mdi_comment_processing_outline MEMBER mdi_comment_processing_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_question MEMBER mdi_comment_question CONSTANT)
    Q_PROPERTY(QString mdi_comment_question_outline MEMBER mdi_comment_question_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_remove MEMBER mdi_comment_remove CONSTANT)
    Q_PROPERTY(QString mdi_comment_remove_outline MEMBER mdi_comment_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_search MEMBER mdi_comment_search CONSTANT)
    Q_PROPERTY(QString mdi_comment_search_outline MEMBER mdi_comment_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_text MEMBER mdi_comment_text CONSTANT)
    Q_PROPERTY(QString mdi_comment_text_multiple MEMBER mdi_comment_text_multiple CONSTANT)
    Q_PROPERTY(QString mdi_comment_text_multiple_outline MEMBER mdi_comment_text_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_comment_text_outline MEMBER mdi_comment_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_compare MEMBER mdi_compare CONSTANT)
    Q_PROPERTY(QString mdi_compass MEMBER mdi_compass CONSTANT)
    Q_PROPERTY(QString mdi_compass_off MEMBER mdi_compass_off CONSTANT)
    Q_PROPERTY(QString mdi_compass_off_outline MEMBER mdi_compass_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_compass_outline MEMBER mdi_compass_outline CONSTANT)
    Q_PROPERTY(QString mdi_console MEMBER mdi_console CONSTANT)
    Q_PROPERTY(QString mdi_console_line MEMBER mdi_console_line CONSTANT)
    Q_PROPERTY(QString mdi_console_network MEMBER mdi_console_network CONSTANT)
    Q_PROPERTY(QString mdi_console_network_outline MEMBER mdi_console_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_contact_mail MEMBER mdi_contact_mail CONSTANT)
    Q_PROPERTY(QString mdi_contactless_payment MEMBER mdi_contactless_payment CONSTANT)
    Q_PROPERTY(QString mdi_contacts MEMBER mdi_contacts CONSTANT)
    Q_PROPERTY(QString mdi_contain MEMBER mdi_contain CONSTANT)
    Q_PROPERTY(QString mdi_contain_end MEMBER mdi_contain_end CONSTANT)
    Q_PROPERTY(QString mdi_contain_start MEMBER mdi_contain_start CONSTANT)
    Q_PROPERTY(QString mdi_content_copy MEMBER mdi_content_copy CONSTANT)
    Q_PROPERTY(QString mdi_content_cut MEMBER mdi_content_cut CONSTANT)
    Q_PROPERTY(QString mdi_content_duplicate MEMBER mdi_content_duplicate CONSTANT)
    Q_PROPERTY(QString mdi_content_paste MEMBER mdi_content_paste CONSTANT)
    Q_PROPERTY(QString mdi_content_save MEMBER mdi_content_save CONSTANT)
    Q_PROPERTY(QString mdi_content_save_all MEMBER mdi_content_save_all CONSTANT)
    Q_PROPERTY(QString mdi_content_save_edit MEMBER mdi_content_save_edit CONSTANT)
    Q_PROPERTY(QString mdi_content_save_edit_outline MEMBER mdi_content_save_edit_outline CONSTANT)
    Q_PROPERTY(QString mdi_content_save_outline MEMBER mdi_content_save_outline CONSTANT)
    Q_PROPERTY(QString mdi_content_save_settings MEMBER mdi_content_save_settings CONSTANT)
    Q_PROPERTY(QString mdi_content_save_settings_outline MEMBER mdi_content_save_settings_outline CONSTANT)
    Q_PROPERTY(QString mdi_contrast MEMBER mdi_contrast CONSTANT)
    Q_PROPERTY(QString mdi_contrast_box MEMBER mdi_contrast_box CONSTANT)
    Q_PROPERTY(QString mdi_contrast_circle MEMBER mdi_contrast_circle CONSTANT)
    Q_PROPERTY(QString mdi_controller_classic MEMBER mdi_controller_classic CONSTANT)
    Q_PROPERTY(QString mdi_controller_classic_outline MEMBER mdi_controller_classic_outline CONSTANT)
    Q_PROPERTY(QString mdi_cookie MEMBER mdi_cookie CONSTANT)
    Q_PROPERTY(QString mdi_copyright MEMBER mdi_copyright CONSTANT)
    Q_PROPERTY(QString mdi_cordova MEMBER mdi_cordova CONSTANT)
    Q_PROPERTY(QString mdi_corn MEMBER mdi_corn CONSTANT)
    Q_PROPERTY(QString mdi_counter MEMBER mdi_counter CONSTANT)
    Q_PROPERTY(QString mdi_cow MEMBER mdi_cow CONSTANT)
    Q_PROPERTY(QString mdi_crane MEMBER mdi_crane CONSTANT)
    Q_PROPERTY(QString mdi_creation MEMBER mdi_creation CONSTANT)
    Q_PROPERTY(QString mdi_creative_commons MEMBER mdi_creative_commons CONSTANT)
    Q_PROPERTY(QString mdi_credit_card MEMBER mdi_credit_card CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_marker MEMBER mdi_credit_card_marker CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_multiple MEMBER mdi_credit_card_multiple CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_off MEMBER mdi_credit_card_off CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_plus MEMBER mdi_credit_card_plus CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_refund MEMBER mdi_credit_card_refund CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_scan MEMBER mdi_credit_card_scan CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_settings MEMBER mdi_credit_card_settings CONSTANT)
    Q_PROPERTY(QString mdi_credit_card_wireless MEMBER mdi_credit_card_wireless CONSTANT)
    Q_PROPERTY(QString mdi_cricket MEMBER mdi_cricket CONSTANT)
    Q_PROPERTY(QString mdi_crop MEMBER mdi_crop CONSTANT)
    Q_PROPERTY(QString mdi_crop_free MEMBER mdi_crop_free CONSTANT)
    Q_PROPERTY(QString mdi_crop_landscape MEMBER mdi_crop_landscape CONSTANT)
    Q_PROPERTY(QString mdi_crop_portrait MEMBER mdi_crop_portrait CONSTANT)
    Q_PROPERTY(QString mdi_crop_rotate MEMBER mdi_crop_rotate CONSTANT)
    Q_PROPERTY(QString mdi_crop_square MEMBER mdi_crop_square CONSTANT)
    Q_PROPERTY(QString mdi_crosshairs MEMBER mdi_crosshairs CONSTANT)
    Q_PROPERTY(QString mdi_crosshairs_gps MEMBER mdi_crosshairs_gps CONSTANT)
    Q_PROPERTY(QString mdi_crown MEMBER mdi_crown CONSTANT)
    Q_PROPERTY(QString mdi_cryengine MEMBER mdi_cryengine CONSTANT)
    Q_PROPERTY(QString mdi_crystal_ball MEMBER mdi_crystal_ball CONSTANT)
    Q_PROPERTY(QString mdi_cube MEMBER mdi_cube CONSTANT)
    Q_PROPERTY(QString mdi_cube_outline MEMBER mdi_cube_outline CONSTANT)
    Q_PROPERTY(QString mdi_cube_scan MEMBER mdi_cube_scan CONSTANT)
    Q_PROPERTY(QString mdi_cube_send MEMBER mdi_cube_send CONSTANT)
    Q_PROPERTY(QString mdi_cube_unfolded MEMBER mdi_cube_unfolded CONSTANT)
    Q_PROPERTY(QString mdi_cup MEMBER mdi_cup CONSTANT)
    Q_PROPERTY(QString mdi_cup_off MEMBER mdi_cup_off CONSTANT)
    Q_PROPERTY(QString mdi_cup_water MEMBER mdi_cup_water CONSTANT)
    Q_PROPERTY(QString mdi_cupcake MEMBER mdi_cupcake CONSTANT)
    Q_PROPERTY(QString mdi_curling MEMBER mdi_curling CONSTANT)
    Q_PROPERTY(QString mdi_currency_bdt MEMBER mdi_currency_bdt CONSTANT)
    Q_PROPERTY(QString mdi_currency_brl MEMBER mdi_currency_brl CONSTANT)
    Q_PROPERTY(QString mdi_currency_btc MEMBER mdi_currency_btc CONSTANT)
    Q_PROPERTY(QString mdi_currency_chf MEMBER mdi_currency_chf CONSTANT)
    Q_PROPERTY(QString mdi_currency_cny MEMBER mdi_currency_cny CONSTANT)
    Q_PROPERTY(QString mdi_currency_eth MEMBER mdi_currency_eth CONSTANT)
    Q_PROPERTY(QString mdi_currency_eur MEMBER mdi_currency_eur CONSTANT)
    Q_PROPERTY(QString mdi_currency_gbp MEMBER mdi_currency_gbp CONSTANT)
    Q_PROPERTY(QString mdi_currency_ils MEMBER mdi_currency_ils CONSTANT)
    Q_PROPERTY(QString mdi_currency_inr MEMBER mdi_currency_inr CONSTANT)
    Q_PROPERTY(QString mdi_currency_jpy MEMBER mdi_currency_jpy CONSTANT)
    Q_PROPERTY(QString mdi_currency_krw MEMBER mdi_currency_krw CONSTANT)
    Q_PROPERTY(QString mdi_currency_kzt MEMBER mdi_currency_kzt CONSTANT)
    Q_PROPERTY(QString mdi_currency_ngn MEMBER mdi_currency_ngn CONSTANT)
    Q_PROPERTY(QString mdi_currency_php MEMBER mdi_currency_php CONSTANT)
    Q_PROPERTY(QString mdi_currency_rub MEMBER mdi_currency_rub CONSTANT)
    Q_PROPERTY(QString mdi_currency_sign MEMBER mdi_currency_sign CONSTANT)
    Q_PROPERTY(QString mdi_currency_try MEMBER mdi_currency_try CONSTANT)
    Q_PROPERTY(QString mdi_currency_twd MEMBER mdi_currency_twd CONSTANT)
    Q_PROPERTY(QString mdi_currency_usd MEMBER mdi_currency_usd CONSTANT)
    Q_PROPERTY(QString mdi_currency_usd_off MEMBER mdi_currency_usd_off CONSTANT)
    Q_PROPERTY(QString mdi_current_ac MEMBER mdi_current_ac CONSTANT)
    Q_PROPERTY(QString mdi_current_dc MEMBER mdi_current_dc CONSTANT)
    Q_PROPERTY(QString mdi_cursor_default MEMBER mdi_cursor_default CONSTANT)
    Q_PROPERTY(QString mdi_cursor_default_click MEMBER mdi_cursor_default_click CONSTANT)
    Q_PROPERTY(QString mdi_cursor_default_click_outline MEMBER mdi_cursor_default_click_outline CONSTANT)
    Q_PROPERTY(QString mdi_cursor_default_outline MEMBER mdi_cursor_default_outline CONSTANT)
    Q_PROPERTY(QString mdi_cursor_move MEMBER mdi_cursor_move CONSTANT)
    Q_PROPERTY(QString mdi_cursor_pointer MEMBER mdi_cursor_pointer CONSTANT)
    Q_PROPERTY(QString mdi_cursor_text MEMBER mdi_cursor_text CONSTANT)
    Q_PROPERTY(QString mdi_database MEMBER mdi_database CONSTANT)
    Q_PROPERTY(QString mdi_database_check MEMBER mdi_database_check CONSTANT)
    Q_PROPERTY(QString mdi_database_edit MEMBER mdi_database_edit CONSTANT)
    Q_PROPERTY(QString mdi_database_export MEMBER mdi_database_export CONSTANT)
    Q_PROPERTY(QString mdi_database_import MEMBER mdi_database_import CONSTANT)
    Q_PROPERTY(QString mdi_database_lock MEMBER mdi_database_lock CONSTANT)
    Q_PROPERTY(QString mdi_database_minus MEMBER mdi_database_minus CONSTANT)
    Q_PROPERTY(QString mdi_database_plus MEMBER mdi_database_plus CONSTANT)
    Q_PROPERTY(QString mdi_database_refresh MEMBER mdi_database_refresh CONSTANT)
    Q_PROPERTY(QString mdi_database_remove MEMBER mdi_database_remove CONSTANT)
    Q_PROPERTY(QString mdi_database_search MEMBER mdi_database_search CONSTANT)
    Q_PROPERTY(QString mdi_database_settings MEMBER mdi_database_settings CONSTANT)
    Q_PROPERTY(QString mdi_death_star MEMBER mdi_death_star CONSTANT)
    Q_PROPERTY(QString mdi_death_star_variant MEMBER mdi_death_star_variant CONSTANT)
    Q_PROPERTY(QString mdi_deathly_hallows MEMBER mdi_deathly_hallows CONSTANT)
    Q_PROPERTY(QString mdi_debian MEMBER mdi_debian CONSTANT)
    Q_PROPERTY(QString mdi_debug_step_into MEMBER mdi_debug_step_into CONSTANT)
    Q_PROPERTY(QString mdi_debug_step_out MEMBER mdi_debug_step_out CONSTANT)
    Q_PROPERTY(QString mdi_debug_step_over MEMBER mdi_debug_step_over CONSTANT)
    Q_PROPERTY(QString mdi_decagram MEMBER mdi_decagram CONSTANT)
    Q_PROPERTY(QString mdi_decagram_outline MEMBER mdi_decagram_outline CONSTANT)
    Q_PROPERTY(QString mdi_decimal_decrease MEMBER mdi_decimal_decrease CONSTANT)
    Q_PROPERTY(QString mdi_decimal_increase MEMBER mdi_decimal_increase CONSTANT)
    Q_PROPERTY(QString mdi_delete MEMBER mdi_delete CONSTANT)
    Q_PROPERTY(QString mdi_delete_circle MEMBER mdi_delete_circle CONSTANT)
    Q_PROPERTY(QString mdi_delete_circle_outline MEMBER mdi_delete_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_delete_empty MEMBER mdi_delete_empty CONSTANT)
    Q_PROPERTY(QString mdi_delete_forever MEMBER mdi_delete_forever CONSTANT)
    Q_PROPERTY(QString mdi_delete_forever_outline MEMBER mdi_delete_forever_outline CONSTANT)
    Q_PROPERTY(QString mdi_delete_outline MEMBER mdi_delete_outline CONSTANT)
    Q_PROPERTY(QString mdi_delete_restore MEMBER mdi_delete_restore CONSTANT)
    Q_PROPERTY(QString mdi_delete_sweep MEMBER mdi_delete_sweep CONSTANT)
    Q_PROPERTY(QString mdi_delete_sweep_outline MEMBER mdi_delete_sweep_outline CONSTANT)
    Q_PROPERTY(QString mdi_delete_variant MEMBER mdi_delete_variant CONSTANT)
    Q_PROPERTY(QString mdi_delta MEMBER mdi_delta CONSTANT)
    Q_PROPERTY(QString mdi_desk_lamp MEMBER mdi_desk_lamp CONSTANT)
    Q_PROPERTY(QString mdi_deskphone MEMBER mdi_deskphone CONSTANT)
    Q_PROPERTY(QString mdi_desktop_classic MEMBER mdi_desktop_classic CONSTANT)
    Q_PROPERTY(QString mdi_desktop_mac MEMBER mdi_desktop_mac CONSTANT)
    Q_PROPERTY(QString mdi_desktop_mac_dashboard MEMBER mdi_desktop_mac_dashboard CONSTANT)
    Q_PROPERTY(QString mdi_desktop_tower MEMBER mdi_desktop_tower CONSTANT)
    Q_PROPERTY(QString mdi_desktop_tower_monitor MEMBER mdi_desktop_tower_monitor CONSTANT)
    Q_PROPERTY(QString mdi_details MEMBER mdi_details CONSTANT)
    Q_PROPERTY(QString mdi_dev_to MEMBER mdi_dev_to CONSTANT)
    Q_PROPERTY(QString mdi_developer_board MEMBER mdi_developer_board CONSTANT)
    Q_PROPERTY(QString mdi_deviantart MEMBER mdi_deviantart CONSTANT)
    Q_PROPERTY(QString mdi_dialpad MEMBER mdi_dialpad CONSTANT)
    Q_PROPERTY(QString mdi_diameter MEMBER mdi_diameter CONSTANT)
    Q_PROPERTY(QString mdi_diameter_outline MEMBER mdi_diameter_outline CONSTANT)
    Q_PROPERTY(QString mdi_diameter_variant MEMBER mdi_diameter_variant CONSTANT)
    Q_PROPERTY(QString mdi_diamond MEMBER mdi_diamond CONSTANT)
    Q_PROPERTY(QString mdi_diamond_outline MEMBER mdi_diamond_outline CONSTANT)
    Q_PROPERTY(QString mdi_diamond_stone MEMBER mdi_diamond_stone CONSTANT)
    Q_PROPERTY(QString mdi_dice_1 MEMBER mdi_dice_1 CONSTANT)
    Q_PROPERTY(QString mdi_dice_2 MEMBER mdi_dice_2 CONSTANT)
    Q_PROPERTY(QString mdi_dice_3 MEMBER mdi_dice_3 CONSTANT)
    Q_PROPERTY(QString mdi_dice_4 MEMBER mdi_dice_4 CONSTANT)
    Q_PROPERTY(QString mdi_dice_5 MEMBER mdi_dice_5 CONSTANT)
    Q_PROPERTY(QString mdi_dice_6 MEMBER mdi_dice_6 CONSTANT)
    Q_PROPERTY(QString mdi_dice_d10 MEMBER mdi_dice_d10 CONSTANT)
    Q_PROPERTY(QString mdi_dice_d12 MEMBER mdi_dice_d12 CONSTANT)
    Q_PROPERTY(QString mdi_dice_d20 MEMBER mdi_dice_d20 CONSTANT)
    Q_PROPERTY(QString mdi_dice_d4 MEMBER mdi_dice_d4 CONSTANT)
    Q_PROPERTY(QString mdi_dice_d6 MEMBER mdi_dice_d6 CONSTANT)
    Q_PROPERTY(QString mdi_dice_d8 MEMBER mdi_dice_d8 CONSTANT)
    Q_PROPERTY(QString mdi_dice_multiple MEMBER mdi_dice_multiple CONSTANT)
    Q_PROPERTY(QString mdi_dictionary MEMBER mdi_dictionary CONSTANT)
    Q_PROPERTY(QString mdi_dip_switch MEMBER mdi_dip_switch CONSTANT)
    Q_PROPERTY(QString mdi_directions MEMBER mdi_directions CONSTANT)
    Q_PROPERTY(QString mdi_directions_fork MEMBER mdi_directions_fork CONSTANT)
    Q_PROPERTY(QString mdi_disc MEMBER mdi_disc CONSTANT)
    Q_PROPERTY(QString mdi_disc_alert MEMBER mdi_disc_alert CONSTANT)
    Q_PROPERTY(QString mdi_disc_player MEMBER mdi_disc_player CONSTANT)
    Q_PROPERTY(QString mdi_discord MEMBER mdi_discord CONSTANT)
    Q_PROPERTY(QString mdi_dishwasher MEMBER mdi_dishwasher CONSTANT)
    Q_PROPERTY(QString mdi_disqus MEMBER mdi_disqus CONSTANT)
    Q_PROPERTY(QString mdi_disqus_outline MEMBER mdi_disqus_outline CONSTANT)
    Q_PROPERTY(QString mdi_diving_flippers MEMBER mdi_diving_flippers CONSTANT)
    Q_PROPERTY(QString mdi_diving_helmet MEMBER mdi_diving_helmet CONSTANT)
    Q_PROPERTY(QString mdi_diving_scuba MEMBER mdi_diving_scuba CONSTANT)
    Q_PROPERTY(QString mdi_diving_scuba_flag MEMBER mdi_diving_scuba_flag CONSTANT)
    Q_PROPERTY(QString mdi_diving_scuba_tank MEMBER mdi_diving_scuba_tank CONSTANT)
    Q_PROPERTY(QString mdi_diving_scuba_tank_multiple MEMBER mdi_diving_scuba_tank_multiple CONSTANT)
    Q_PROPERTY(QString mdi_diving_snorkel MEMBER mdi_diving_snorkel CONSTANT)
    Q_PROPERTY(QString mdi_division MEMBER mdi_division CONSTANT)
    Q_PROPERTY(QString mdi_division_box MEMBER mdi_division_box CONSTANT)
    Q_PROPERTY(QString mdi_dlna MEMBER mdi_dlna CONSTANT)
    Q_PROPERTY(QString mdi_dna MEMBER mdi_dna CONSTANT)
    Q_PROPERTY(QString mdi_dns MEMBER mdi_dns CONSTANT)
    Q_PROPERTY(QString mdi_dns_outline MEMBER mdi_dns_outline CONSTANT)
    Q_PROPERTY(QString mdi_do_not_disturb MEMBER mdi_do_not_disturb CONSTANT)
    Q_PROPERTY(QString mdi_do_not_disturb_off MEMBER mdi_do_not_disturb_off CONSTANT)
    Q_PROPERTY(QString mdi_docker MEMBER mdi_docker CONSTANT)
    Q_PROPERTY(QString mdi_doctor MEMBER mdi_doctor CONSTANT)
    Q_PROPERTY(QString mdi_dog MEMBER mdi_dog CONSTANT)
    Q_PROPERTY(QString mdi_dog_service MEMBER mdi_dog_service CONSTANT)
    Q_PROPERTY(QString mdi_dog_side MEMBER mdi_dog_side CONSTANT)
    Q_PROPERTY(QString mdi_dolby MEMBER mdi_dolby CONSTANT)
    Q_PROPERTY(QString mdi_domain MEMBER mdi_domain CONSTANT)
    Q_PROPERTY(QString mdi_domain_off MEMBER mdi_domain_off CONSTANT)
    Q_PROPERTY(QString mdi_donkey MEMBER mdi_donkey CONSTANT)
    Q_PROPERTY(QString mdi_door MEMBER mdi_door CONSTANT)
    Q_PROPERTY(QString mdi_door_closed MEMBER mdi_door_closed CONSTANT)
    Q_PROPERTY(QString mdi_door_open MEMBER mdi_door_open CONSTANT)
    Q_PROPERTY(QString mdi_doorbell_video MEMBER mdi_doorbell_video CONSTANT)
    Q_PROPERTY(QString mdi_dot_net MEMBER mdi_dot_net CONSTANT)
    Q_PROPERTY(QString mdi_dots_horizontal MEMBER mdi_dots_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_dots_horizontal_circle MEMBER mdi_dots_horizontal_circle CONSTANT)
    Q_PROPERTY(QString mdi_dots_horizontal_circle_outline MEMBER mdi_dots_horizontal_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_dots_vertical MEMBER mdi_dots_vertical CONSTANT)
    Q_PROPERTY(QString mdi_dots_vertical_circle MEMBER mdi_dots_vertical_circle CONSTANT)
    Q_PROPERTY(QString mdi_dots_vertical_circle_outline MEMBER mdi_dots_vertical_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_douban MEMBER mdi_douban CONSTANT)
    Q_PROPERTY(QString mdi_download MEMBER mdi_download CONSTANT)
    Q_PROPERTY(QString mdi_download_multiple MEMBER mdi_download_multiple CONSTANT)
    Q_PROPERTY(QString mdi_download_network MEMBER mdi_download_network CONSTANT)
    Q_PROPERTY(QString mdi_download_network_outline MEMBER mdi_download_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_download_outline MEMBER mdi_download_outline CONSTANT)
    Q_PROPERTY(QString mdi_drag MEMBER mdi_drag CONSTANT)
    Q_PROPERTY(QString mdi_drag_horizontal MEMBER mdi_drag_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_drag_variant MEMBER mdi_drag_variant CONSTANT)
    Q_PROPERTY(QString mdi_drag_vertical MEMBER mdi_drag_vertical CONSTANT)
    Q_PROPERTY(QString mdi_drama_masks MEMBER mdi_drama_masks CONSTANT)
    Q_PROPERTY(QString mdi_drawing MEMBER mdi_drawing CONSTANT)
    Q_PROPERTY(QString mdi_drawing_box MEMBER mdi_drawing_box CONSTANT)
    Q_PROPERTY(QString mdi_dribbble MEMBER mdi_dribbble CONSTANT)
    Q_PROPERTY(QString mdi_dribbble_box MEMBER mdi_dribbble_box CONSTANT)
    Q_PROPERTY(QString mdi_drone MEMBER mdi_drone CONSTANT)
    Q_PROPERTY(QString mdi_dropbox MEMBER mdi_dropbox CONSTANT)
    Q_PROPERTY(QString mdi_drupal MEMBER mdi_drupal CONSTANT)
    Q_PROPERTY(QString mdi_duck MEMBER mdi_duck CONSTANT)
    Q_PROPERTY(QString mdi_dumbbell MEMBER mdi_dumbbell CONSTANT)
    Q_PROPERTY(QString mdi_dump_truck MEMBER mdi_dump_truck CONSTANT)
    Q_PROPERTY(QString mdi_ear_hearing MEMBER mdi_ear_hearing CONSTANT)
    Q_PROPERTY(QString mdi_ear_hearing_off MEMBER mdi_ear_hearing_off CONSTANT)
    Q_PROPERTY(QString mdi_earth MEMBER mdi_earth CONSTANT)
    Q_PROPERTY(QString mdi_earth_box MEMBER mdi_earth_box CONSTANT)
    Q_PROPERTY(QString mdi_earth_box_off MEMBER mdi_earth_box_off CONSTANT)
    Q_PROPERTY(QString mdi_earth_off MEMBER mdi_earth_off CONSTANT)
    Q_PROPERTY(QString mdi_edge MEMBER mdi_edge CONSTANT)
    Q_PROPERTY(QString mdi_egg MEMBER mdi_egg CONSTANT)
    Q_PROPERTY(QString mdi_egg_easter MEMBER mdi_egg_easter CONSTANT)
    Q_PROPERTY(QString mdi_eight_track MEMBER mdi_eight_track CONSTANT)
    Q_PROPERTY(QString mdi_eject MEMBER mdi_eject CONSTANT)
    Q_PROPERTY(QString mdi_eject_outline MEMBER mdi_eject_outline CONSTANT)
    Q_PROPERTY(QString mdi_elephant MEMBER mdi_elephant CONSTANT)
    Q_PROPERTY(QString mdi_elevation_decline MEMBER mdi_elevation_decline CONSTANT)
    Q_PROPERTY(QString mdi_elevation_rise MEMBER mdi_elevation_rise CONSTANT)
    Q_PROPERTY(QString mdi_elevator MEMBER mdi_elevator CONSTANT)
    Q_PROPERTY(QString mdi_email MEMBER mdi_email CONSTANT)
    Q_PROPERTY(QString mdi_email_alert MEMBER mdi_email_alert CONSTANT)
    Q_PROPERTY(QString mdi_email_box MEMBER mdi_email_box CONSTANT)
    Q_PROPERTY(QString mdi_email_check MEMBER mdi_email_check CONSTANT)
    Q_PROPERTY(QString mdi_email_check_outline MEMBER mdi_email_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_email_lock MEMBER mdi_email_lock CONSTANT)
    Q_PROPERTY(QString mdi_email_mark_as_unread MEMBER mdi_email_mark_as_unread CONSTANT)
    Q_PROPERTY(QString mdi_email_open MEMBER mdi_email_open CONSTANT)
    Q_PROPERTY(QString mdi_email_open_outline MEMBER mdi_email_open_outline CONSTANT)
    Q_PROPERTY(QString mdi_email_outline MEMBER mdi_email_outline CONSTANT)
    Q_PROPERTY(QString mdi_email_plus MEMBER mdi_email_plus CONSTANT)
    Q_PROPERTY(QString mdi_email_plus_outline MEMBER mdi_email_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_email_search MEMBER mdi_email_search CONSTANT)
    Q_PROPERTY(QString mdi_email_search_outline MEMBER mdi_email_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_email_variant MEMBER mdi_email_variant CONSTANT)
    Q_PROPERTY(QString mdi_ember MEMBER mdi_ember CONSTANT)
    Q_PROPERTY(QString mdi_emby MEMBER mdi_emby CONSTANT)
    Q_PROPERTY(QString mdi_emoticon MEMBER mdi_emoticon CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_angry MEMBER mdi_emoticon_angry CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_angry_outline MEMBER mdi_emoticon_angry_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_cool MEMBER mdi_emoticon_cool CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_cool_outline MEMBER mdi_emoticon_cool_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_cry MEMBER mdi_emoticon_cry CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_cry_outline MEMBER mdi_emoticon_cry_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_dead MEMBER mdi_emoticon_dead CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_dead_outline MEMBER mdi_emoticon_dead_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_devil MEMBER mdi_emoticon_devil CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_devil_outline MEMBER mdi_emoticon_devil_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_excited MEMBER mdi_emoticon_excited CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_excited_outline MEMBER mdi_emoticon_excited_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_happy MEMBER mdi_emoticon_happy CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_happy_outline MEMBER mdi_emoticon_happy_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_kiss MEMBER mdi_emoticon_kiss CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_kiss_outline MEMBER mdi_emoticon_kiss_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_neutral MEMBER mdi_emoticon_neutral CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_neutral_outline MEMBER mdi_emoticon_neutral_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_outline MEMBER mdi_emoticon_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_poop MEMBER mdi_emoticon_poop CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_poop_outline MEMBER mdi_emoticon_poop_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_sad MEMBER mdi_emoticon_sad CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_sad_outline MEMBER mdi_emoticon_sad_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_tongue MEMBER mdi_emoticon_tongue CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_tongue_outline MEMBER mdi_emoticon_tongue_outline CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_wink MEMBER mdi_emoticon_wink CONSTANT)
    Q_PROPERTY(QString mdi_emoticon_wink_outline MEMBER mdi_emoticon_wink_outline CONSTANT)
    Q_PROPERTY(QString mdi_engine MEMBER mdi_engine CONSTANT)
    Q_PROPERTY(QString mdi_engine_off MEMBER mdi_engine_off CONSTANT)
    Q_PROPERTY(QString mdi_engine_off_outline MEMBER mdi_engine_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_engine_outline MEMBER mdi_engine_outline CONSTANT)
    Q_PROPERTY(QString mdi_equal MEMBER mdi_equal CONSTANT)
    Q_PROPERTY(QString mdi_equal_box MEMBER mdi_equal_box CONSTANT)
    Q_PROPERTY(QString mdi_eraser MEMBER mdi_eraser CONSTANT)
    Q_PROPERTY(QString mdi_eraser_variant MEMBER mdi_eraser_variant CONSTANT)
    Q_PROPERTY(QString mdi_escalator MEMBER mdi_escalator CONSTANT)
    Q_PROPERTY(QString mdi_eslint MEMBER mdi_eslint CONSTANT)
    Q_PROPERTY(QString mdi_et MEMBER mdi_et CONSTANT)
    Q_PROPERTY(QString mdi_ethereum MEMBER mdi_ethereum CONSTANT)
    Q_PROPERTY(QString mdi_ethernet MEMBER mdi_ethernet CONSTANT)
    Q_PROPERTY(QString mdi_ethernet_cable MEMBER mdi_ethernet_cable CONSTANT)
    Q_PROPERTY(QString mdi_ethernet_cable_off MEMBER mdi_ethernet_cable_off CONSTANT)
    Q_PROPERTY(QString mdi_etsy MEMBER mdi_etsy CONSTANT)
    Q_PROPERTY(QString mdi_ev_station MEMBER mdi_ev_station CONSTANT)
    Q_PROPERTY(QString mdi_eventbrite MEMBER mdi_eventbrite CONSTANT)
    Q_PROPERTY(QString mdi_evernote MEMBER mdi_evernote CONSTANT)
    Q_PROPERTY(QString mdi_exclamation MEMBER mdi_exclamation CONSTANT)
    Q_PROPERTY(QString mdi_exit_run MEMBER mdi_exit_run CONSTANT)
    Q_PROPERTY(QString mdi_exit_to_app MEMBER mdi_exit_to_app CONSTANT)
    Q_PROPERTY(QString mdi_expand_all MEMBER mdi_expand_all CONSTANT)
    Q_PROPERTY(QString mdi_expand_all_outline MEMBER mdi_expand_all_outline CONSTANT)
    Q_PROPERTY(QString mdi_exponent MEMBER mdi_exponent CONSTANT)
    Q_PROPERTY(QString mdi_exponent_box MEMBER mdi_exponent_box CONSTANT)
    Q_PROPERTY(QString mdi_export MEMBER mdi_export CONSTANT)
    Q_PROPERTY(QString mdi_export_variant MEMBER mdi_export_variant CONSTANT)
    Q_PROPERTY(QString mdi_eye MEMBER mdi_eye CONSTANT)
    Q_PROPERTY(QString mdi_eye_check MEMBER mdi_eye_check CONSTANT)
    Q_PROPERTY(QString mdi_eye_check_outline MEMBER mdi_eye_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_eye_circle MEMBER mdi_eye_circle CONSTANT)
    Q_PROPERTY(QString mdi_eye_circle_outline MEMBER mdi_eye_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_eye_off MEMBER mdi_eye_off CONSTANT)
    Q_PROPERTY(QString mdi_eye_off_outline MEMBER mdi_eye_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_eye_outline MEMBER mdi_eye_outline CONSTANT)
    Q_PROPERTY(QString mdi_eye_plus MEMBER mdi_eye_plus CONSTANT)
    Q_PROPERTY(QString mdi_eye_plus_outline MEMBER mdi_eye_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_eye_settings MEMBER mdi_eye_settings CONSTANT)
    Q_PROPERTY(QString mdi_eye_settings_outline MEMBER mdi_eye_settings_outline CONSTANT)
    Q_PROPERTY(QString mdi_eyedropper MEMBER mdi_eyedropper CONSTANT)
    Q_PROPERTY(QString mdi_eyedropper_variant MEMBER mdi_eyedropper_variant CONSTANT)
    Q_PROPERTY(QString mdi_face MEMBER mdi_face CONSTANT)
    Q_PROPERTY(QString mdi_face_agent MEMBER mdi_face_agent CONSTANT)
    Q_PROPERTY(QString mdi_face_outline MEMBER mdi_face_outline CONSTANT)
    Q_PROPERTY(QString mdi_face_profile MEMBER mdi_face_profile CONSTANT)
    Q_PROPERTY(QString mdi_face_recognition MEMBER mdi_face_recognition CONSTANT)
    Q_PROPERTY(QString mdi_facebook MEMBER mdi_facebook CONSTANT)
    Q_PROPERTY(QString mdi_facebook_box MEMBER mdi_facebook_box CONSTANT)
    Q_PROPERTY(QString mdi_facebook_messenger MEMBER mdi_facebook_messenger CONSTANT)
    Q_PROPERTY(QString mdi_facebook_workplace MEMBER mdi_facebook_workplace CONSTANT)
    Q_PROPERTY(QString mdi_factory MEMBER mdi_factory CONSTANT)
    Q_PROPERTY(QString mdi_fan MEMBER mdi_fan CONSTANT)
    Q_PROPERTY(QString mdi_fan_off MEMBER mdi_fan_off CONSTANT)
    Q_PROPERTY(QString mdi_fast_forward MEMBER mdi_fast_forward CONSTANT)
    Q_PROPERTY(QString mdi_fast_forward_10 MEMBER mdi_fast_forward_10 CONSTANT)
    Q_PROPERTY(QString mdi_fast_forward_30 MEMBER mdi_fast_forward_30 CONSTANT)
    Q_PROPERTY(QString mdi_fast_forward_outline MEMBER mdi_fast_forward_outline CONSTANT)
    Q_PROPERTY(QString mdi_fax MEMBER mdi_fax CONSTANT)
    Q_PROPERTY(QString mdi_feather MEMBER mdi_feather CONSTANT)
    Q_PROPERTY(QString mdi_feature_search MEMBER mdi_feature_search CONSTANT)
    Q_PROPERTY(QString mdi_feature_search_outline MEMBER mdi_feature_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_fedora MEMBER mdi_fedora CONSTANT)
    Q_PROPERTY(QString mdi_ferry MEMBER mdi_ferry CONSTANT)
    Q_PROPERTY(QString mdi_file MEMBER mdi_file CONSTANT)
    Q_PROPERTY(QString mdi_file_account MEMBER mdi_file_account CONSTANT)
    Q_PROPERTY(QString mdi_file_alert MEMBER mdi_file_alert CONSTANT)
    Q_PROPERTY(QString mdi_file_alert_outline MEMBER mdi_file_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_cabinet MEMBER mdi_file_cabinet CONSTANT)
    Q_PROPERTY(QString mdi_file_cancel MEMBER mdi_file_cancel CONSTANT)
    Q_PROPERTY(QString mdi_file_cancel_outline MEMBER mdi_file_cancel_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_chart MEMBER mdi_file_chart CONSTANT)
    Q_PROPERTY(QString mdi_file_check MEMBER mdi_file_check CONSTANT)
    Q_PROPERTY(QString mdi_file_cloud MEMBER mdi_file_cloud CONSTANT)
    Q_PROPERTY(QString mdi_file_compare MEMBER mdi_file_compare CONSTANT)
    Q_PROPERTY(QString mdi_file_delimited MEMBER mdi_file_delimited CONSTANT)
    Q_PROPERTY(QString mdi_file_document MEMBER mdi_file_document CONSTANT)
    Q_PROPERTY(QString mdi_file_document_box MEMBER mdi_file_document_box CONSTANT)
    Q_PROPERTY(QString mdi_file_document_box_multiple MEMBER mdi_file_document_box_multiple CONSTANT)
    Q_PROPERTY(QString mdi_file_document_box_multiple_outline MEMBER mdi_file_document_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_document_box_outline MEMBER mdi_file_document_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_document_edit MEMBER mdi_file_document_edit CONSTANT)
    Q_PROPERTY(QString mdi_file_document_edit_outline MEMBER mdi_file_document_edit_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_document_outline MEMBER mdi_file_document_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_download MEMBER mdi_file_download CONSTANT)
    Q_PROPERTY(QString mdi_file_download_outline MEMBER mdi_file_download_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_excel MEMBER mdi_file_excel CONSTANT)
    Q_PROPERTY(QString mdi_file_excel_box MEMBER mdi_file_excel_box CONSTANT)
    Q_PROPERTY(QString mdi_file_export MEMBER mdi_file_export CONSTANT)
    Q_PROPERTY(QString mdi_file_eye MEMBER mdi_file_eye CONSTANT)
    Q_PROPERTY(QString mdi_file_eye_outline MEMBER mdi_file_eye_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_find MEMBER mdi_file_find CONSTANT)
    Q_PROPERTY(QString mdi_file_find_outline MEMBER mdi_file_find_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_hidden MEMBER mdi_file_hidden CONSTANT)
    Q_PROPERTY(QString mdi_file_image MEMBER mdi_file_image CONSTANT)
    Q_PROPERTY(QString mdi_file_import MEMBER mdi_file_import CONSTANT)
    Q_PROPERTY(QString mdi_file_lock MEMBER mdi_file_lock CONSTANT)
    Q_PROPERTY(QString mdi_file_move MEMBER mdi_file_move CONSTANT)
    Q_PROPERTY(QString mdi_file_multiple MEMBER mdi_file_multiple CONSTANT)
    Q_PROPERTY(QString mdi_file_music MEMBER mdi_file_music CONSTANT)
    Q_PROPERTY(QString mdi_file_outline MEMBER mdi_file_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_pdf MEMBER mdi_file_pdf CONSTANT)
    Q_PROPERTY(QString mdi_file_pdf_box MEMBER mdi_file_pdf_box CONSTANT)
    Q_PROPERTY(QString mdi_file_percent MEMBER mdi_file_percent CONSTANT)
    Q_PROPERTY(QString mdi_file_plus MEMBER mdi_file_plus CONSTANT)
    Q_PROPERTY(QString mdi_file_powerpoint MEMBER mdi_file_powerpoint CONSTANT)
    Q_PROPERTY(QString mdi_file_powerpoint_box MEMBER mdi_file_powerpoint_box CONSTANT)
    Q_PROPERTY(QString mdi_file_presentation_box MEMBER mdi_file_presentation_box CONSTANT)
    Q_PROPERTY(QString mdi_file_question MEMBER mdi_file_question CONSTANT)
    Q_PROPERTY(QString mdi_file_remove MEMBER mdi_file_remove CONSTANT)
    Q_PROPERTY(QString mdi_file_replace MEMBER mdi_file_replace CONSTANT)
    Q_PROPERTY(QString mdi_file_replace_outline MEMBER mdi_file_replace_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_restore MEMBER mdi_file_restore CONSTANT)
    Q_PROPERTY(QString mdi_file_search MEMBER mdi_file_search CONSTANT)
    Q_PROPERTY(QString mdi_file_search_outline MEMBER mdi_file_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_send MEMBER mdi_file_send CONSTANT)
    Q_PROPERTY(QString mdi_file_table MEMBER mdi_file_table CONSTANT)
    Q_PROPERTY(QString mdi_file_table_outline MEMBER mdi_file_table_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_tree MEMBER mdi_file_tree CONSTANT)
    Q_PROPERTY(QString mdi_file_undo MEMBER mdi_file_undo CONSTANT)
    Q_PROPERTY(QString mdi_file_upload MEMBER mdi_file_upload CONSTANT)
    Q_PROPERTY(QString mdi_file_upload_outline MEMBER mdi_file_upload_outline CONSTANT)
    Q_PROPERTY(QString mdi_file_video MEMBER mdi_file_video CONSTANT)
    Q_PROPERTY(QString mdi_file_word MEMBER mdi_file_word CONSTANT)
    Q_PROPERTY(QString mdi_file_word_box MEMBER mdi_file_word_box CONSTANT)
    Q_PROPERTY(QString mdi_file_xml MEMBER mdi_file_xml CONSTANT)
    Q_PROPERTY(QString mdi_film MEMBER mdi_film CONSTANT)
    Q_PROPERTY(QString mdi_filmstrip MEMBER mdi_filmstrip CONSTANT)
    Q_PROPERTY(QString mdi_filmstrip_off MEMBER mdi_filmstrip_off CONSTANT)
    Q_PROPERTY(QString mdi_filter MEMBER mdi_filter CONSTANT)
    Q_PROPERTY(QString mdi_filter_outline MEMBER mdi_filter_outline CONSTANT)
    Q_PROPERTY(QString mdi_filter_remove MEMBER mdi_filter_remove CONSTANT)
    Q_PROPERTY(QString mdi_filter_remove_outline MEMBER mdi_filter_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_filter_variant MEMBER mdi_filter_variant CONSTANT)
    Q_PROPERTY(QString mdi_finance MEMBER mdi_finance CONSTANT)
    Q_PROPERTY(QString mdi_find_replace MEMBER mdi_find_replace CONSTANT)
    Q_PROPERTY(QString mdi_fingerprint MEMBER mdi_fingerprint CONSTANT)
    Q_PROPERTY(QString mdi_fire MEMBER mdi_fire CONSTANT)
    Q_PROPERTY(QString mdi_fire_truck MEMBER mdi_fire_truck CONSTANT)
    Q_PROPERTY(QString mdi_firebase MEMBER mdi_firebase CONSTANT)
    Q_PROPERTY(QString mdi_firefox MEMBER mdi_firefox CONSTANT)
    Q_PROPERTY(QString mdi_fish MEMBER mdi_fish CONSTANT)
    Q_PROPERTY(QString mdi_flag MEMBER mdi_flag CONSTANT)
    Q_PROPERTY(QString mdi_flag_checkered MEMBER mdi_flag_checkered CONSTANT)
    Q_PROPERTY(QString mdi_flag_minus MEMBER mdi_flag_minus CONSTANT)
    Q_PROPERTY(QString mdi_flag_outline MEMBER mdi_flag_outline CONSTANT)
    Q_PROPERTY(QString mdi_flag_plus MEMBER mdi_flag_plus CONSTANT)
    Q_PROPERTY(QString mdi_flag_remove MEMBER mdi_flag_remove CONSTANT)
    Q_PROPERTY(QString mdi_flag_triangle MEMBER mdi_flag_triangle CONSTANT)
    Q_PROPERTY(QString mdi_flag_variant MEMBER mdi_flag_variant CONSTANT)
    Q_PROPERTY(QString mdi_flag_variant_outline MEMBER mdi_flag_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_flare MEMBER mdi_flare CONSTANT)
    Q_PROPERTY(QString mdi_flash MEMBER mdi_flash CONSTANT)
    Q_PROPERTY(QString mdi_flash_auto MEMBER mdi_flash_auto CONSTANT)
    Q_PROPERTY(QString mdi_flash_circle MEMBER mdi_flash_circle CONSTANT)
    Q_PROPERTY(QString mdi_flash_off MEMBER mdi_flash_off CONSTANT)
    Q_PROPERTY(QString mdi_flash_outline MEMBER mdi_flash_outline CONSTANT)
    Q_PROPERTY(QString mdi_flash_red_eye MEMBER mdi_flash_red_eye CONSTANT)
    Q_PROPERTY(QString mdi_flashlight MEMBER mdi_flashlight CONSTANT)
    Q_PROPERTY(QString mdi_flashlight_off MEMBER mdi_flashlight_off CONSTANT)
    Q_PROPERTY(QString mdi_flask MEMBER mdi_flask CONSTANT)
    Q_PROPERTY(QString mdi_flask_empty MEMBER mdi_flask_empty CONSTANT)
    Q_PROPERTY(QString mdi_flask_empty_outline MEMBER mdi_flask_empty_outline CONSTANT)
    Q_PROPERTY(QString mdi_flask_outline MEMBER mdi_flask_outline CONSTANT)
    Q_PROPERTY(QString mdi_flattr MEMBER mdi_flattr CONSTANT)
    Q_PROPERTY(QString mdi_flickr MEMBER mdi_flickr CONSTANT)
    Q_PROPERTY(QString mdi_flip_to_back MEMBER mdi_flip_to_back CONSTANT)
    Q_PROPERTY(QString mdi_flip_to_front MEMBER mdi_flip_to_front CONSTANT)
    Q_PROPERTY(QString mdi_floor_lamp MEMBER mdi_floor_lamp CONSTANT)
    Q_PROPERTY(QString mdi_floor_plan MEMBER mdi_floor_plan CONSTANT)
    Q_PROPERTY(QString mdi_floppy MEMBER mdi_floppy CONSTANT)
    Q_PROPERTY(QString mdi_floppy_variant MEMBER mdi_floppy_variant CONSTANT)
    Q_PROPERTY(QString mdi_flower MEMBER mdi_flower CONSTANT)
    Q_PROPERTY(QString mdi_flower_outline MEMBER mdi_flower_outline CONSTANT)
    Q_PROPERTY(QString mdi_flower_poppy MEMBER mdi_flower_poppy CONSTANT)
    Q_PROPERTY(QString mdi_flower_tulip MEMBER mdi_flower_tulip CONSTANT)
    Q_PROPERTY(QString mdi_flower_tulip_outline MEMBER mdi_flower_tulip_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder MEMBER mdi_folder CONSTANT)
    Q_PROPERTY(QString mdi_folder_account MEMBER mdi_folder_account CONSTANT)
    Q_PROPERTY(QString mdi_folder_account_outline MEMBER mdi_folder_account_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_alert MEMBER mdi_folder_alert CONSTANT)
    Q_PROPERTY(QString mdi_folder_alert_outline MEMBER mdi_folder_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_clock MEMBER mdi_folder_clock CONSTANT)
    Q_PROPERTY(QString mdi_folder_clock_outline MEMBER mdi_folder_clock_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_download MEMBER mdi_folder_download CONSTANT)
    Q_PROPERTY(QString mdi_folder_edit MEMBER mdi_folder_edit CONSTANT)
    Q_PROPERTY(QString mdi_folder_edit_outline MEMBER mdi_folder_edit_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_google_drive MEMBER mdi_folder_google_drive CONSTANT)
    Q_PROPERTY(QString mdi_folder_image MEMBER mdi_folder_image CONSTANT)
    Q_PROPERTY(QString mdi_folder_key MEMBER mdi_folder_key CONSTANT)
    Q_PROPERTY(QString mdi_folder_key_network MEMBER mdi_folder_key_network CONSTANT)
    Q_PROPERTY(QString mdi_folder_key_network_outline MEMBER mdi_folder_key_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_lock MEMBER mdi_folder_lock CONSTANT)
    Q_PROPERTY(QString mdi_folder_lock_open MEMBER mdi_folder_lock_open CONSTANT)
    Q_PROPERTY(QString mdi_folder_move MEMBER mdi_folder_move CONSTANT)
    Q_PROPERTY(QString mdi_folder_multiple MEMBER mdi_folder_multiple CONSTANT)
    Q_PROPERTY(QString mdi_folder_multiple_image MEMBER mdi_folder_multiple_image CONSTANT)
    Q_PROPERTY(QString mdi_folder_multiple_outline MEMBER mdi_folder_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_network MEMBER mdi_folder_network CONSTANT)
    Q_PROPERTY(QString mdi_folder_network_outline MEMBER mdi_folder_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_open MEMBER mdi_folder_open CONSTANT)
    Q_PROPERTY(QString mdi_folder_open_outline MEMBER mdi_folder_open_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_outline MEMBER mdi_folder_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_plus MEMBER mdi_folder_plus CONSTANT)
    Q_PROPERTY(QString mdi_folder_plus_outline MEMBER mdi_folder_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_pound MEMBER mdi_folder_pound CONSTANT)
    Q_PROPERTY(QString mdi_folder_pound_outline MEMBER mdi_folder_pound_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_remove MEMBER mdi_folder_remove CONSTANT)
    Q_PROPERTY(QString mdi_folder_remove_outline MEMBER mdi_folder_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_search MEMBER mdi_folder_search CONSTANT)
    Q_PROPERTY(QString mdi_folder_search_outline MEMBER mdi_folder_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_star MEMBER mdi_folder_star CONSTANT)
    Q_PROPERTY(QString mdi_folder_star_outline MEMBER mdi_folder_star_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_sync MEMBER mdi_folder_sync CONSTANT)
    Q_PROPERTY(QString mdi_folder_sync_outline MEMBER mdi_folder_sync_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_text MEMBER mdi_folder_text CONSTANT)
    Q_PROPERTY(QString mdi_folder_text_outline MEMBER mdi_folder_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_folder_upload MEMBER mdi_folder_upload CONSTANT)
    Q_PROPERTY(QString mdi_font_awesome MEMBER mdi_font_awesome CONSTANT)
    Q_PROPERTY(QString mdi_food MEMBER mdi_food CONSTANT)
    Q_PROPERTY(QString mdi_food_apple MEMBER mdi_food_apple CONSTANT)
    Q_PROPERTY(QString mdi_food_apple_outline MEMBER mdi_food_apple_outline CONSTANT)
    Q_PROPERTY(QString mdi_food_croissant MEMBER mdi_food_croissant CONSTANT)
    Q_PROPERTY(QString mdi_food_fork_drink MEMBER mdi_food_fork_drink CONSTANT)
    Q_PROPERTY(QString mdi_food_off MEMBER mdi_food_off CONSTANT)
    Q_PROPERTY(QString mdi_food_variant MEMBER mdi_food_variant CONSTANT)
    Q_PROPERTY(QString mdi_football MEMBER mdi_football CONSTANT)
    Q_PROPERTY(QString mdi_football_australian MEMBER mdi_football_australian CONSTANT)
    Q_PROPERTY(QString mdi_football_helmet MEMBER mdi_football_helmet CONSTANT)
    Q_PROPERTY(QString mdi_forklift MEMBER mdi_forklift CONSTANT)
    Q_PROPERTY(QString mdi_format_align_bottom MEMBER mdi_format_align_bottom CONSTANT)
    Q_PROPERTY(QString mdi_format_align_center MEMBER mdi_format_align_center CONSTANT)
    Q_PROPERTY(QString mdi_format_align_justify MEMBER mdi_format_align_justify CONSTANT)
    Q_PROPERTY(QString mdi_format_align_left MEMBER mdi_format_align_left CONSTANT)
    Q_PROPERTY(QString mdi_format_align_middle MEMBER mdi_format_align_middle CONSTANT)
    Q_PROPERTY(QString mdi_format_align_right MEMBER mdi_format_align_right CONSTANT)
    Q_PROPERTY(QString mdi_format_align_top MEMBER mdi_format_align_top CONSTANT)
    Q_PROPERTY(QString mdi_format_annotation_minus MEMBER mdi_format_annotation_minus CONSTANT)
    Q_PROPERTY(QString mdi_format_annotation_plus MEMBER mdi_format_annotation_plus CONSTANT)
    Q_PROPERTY(QString mdi_format_bold MEMBER mdi_format_bold CONSTANT)
    Q_PROPERTY(QString mdi_format_clear MEMBER mdi_format_clear CONSTANT)
    Q_PROPERTY(QString mdi_format_color_fill MEMBER mdi_format_color_fill CONSTANT)
    Q_PROPERTY(QString mdi_format_color_text MEMBER mdi_format_color_text CONSTANT)
    Q_PROPERTY(QString mdi_format_columns MEMBER mdi_format_columns CONSTANT)
    Q_PROPERTY(QString mdi_format_float_center MEMBER mdi_format_float_center CONSTANT)
    Q_PROPERTY(QString mdi_format_float_left MEMBER mdi_format_float_left CONSTANT)
    Q_PROPERTY(QString mdi_format_float_none MEMBER mdi_format_float_none CONSTANT)
    Q_PROPERTY(QString mdi_format_float_right MEMBER mdi_format_float_right CONSTANT)
    Q_PROPERTY(QString mdi_format_font MEMBER mdi_format_font CONSTANT)
    Q_PROPERTY(QString mdi_format_font_size_decrease MEMBER mdi_format_font_size_decrease CONSTANT)
    Q_PROPERTY(QString mdi_format_font_size_increase MEMBER mdi_format_font_size_increase CONSTANT)
    Q_PROPERTY(QString mdi_format_header_1 MEMBER mdi_format_header_1 CONSTANT)
    Q_PROPERTY(QString mdi_format_header_2 MEMBER mdi_format_header_2 CONSTANT)
    Q_PROPERTY(QString mdi_format_header_3 MEMBER mdi_format_header_3 CONSTANT)
    Q_PROPERTY(QString mdi_format_header_4 MEMBER mdi_format_header_4 CONSTANT)
    Q_PROPERTY(QString mdi_format_header_5 MEMBER mdi_format_header_5 CONSTANT)
    Q_PROPERTY(QString mdi_format_header_6 MEMBER mdi_format_header_6 CONSTANT)
    Q_PROPERTY(QString mdi_format_header_decrease MEMBER mdi_format_header_decrease CONSTANT)
    Q_PROPERTY(QString mdi_format_header_equal MEMBER mdi_format_header_equal CONSTANT)
    Q_PROPERTY(QString mdi_format_header_increase MEMBER mdi_format_header_increase CONSTANT)
    Q_PROPERTY(QString mdi_format_header_pound MEMBER mdi_format_header_pound CONSTANT)
    Q_PROPERTY(QString mdi_format_horizontal_align_center MEMBER mdi_format_horizontal_align_center CONSTANT)
    Q_PROPERTY(QString mdi_format_horizontal_align_left MEMBER mdi_format_horizontal_align_left CONSTANT)
    Q_PROPERTY(QString mdi_format_horizontal_align_right MEMBER mdi_format_horizontal_align_right CONSTANT)
    Q_PROPERTY(QString mdi_format_indent_decrease MEMBER mdi_format_indent_decrease CONSTANT)
    Q_PROPERTY(QString mdi_format_indent_increase MEMBER mdi_format_indent_increase CONSTANT)
    Q_PROPERTY(QString mdi_format_italic MEMBER mdi_format_italic CONSTANT)
    Q_PROPERTY(QString mdi_format_letter_case MEMBER mdi_format_letter_case CONSTANT)
    Q_PROPERTY(QString mdi_format_letter_case_lower MEMBER mdi_format_letter_case_lower CONSTANT)
    Q_PROPERTY(QString mdi_format_letter_case_upper MEMBER mdi_format_letter_case_upper CONSTANT)
    Q_PROPERTY(QString mdi_format_line_spacing MEMBER mdi_format_line_spacing CONSTANT)
    Q_PROPERTY(QString mdi_format_line_style MEMBER mdi_format_line_style CONSTANT)
    Q_PROPERTY(QString mdi_format_line_weight MEMBER mdi_format_line_weight CONSTANT)
    Q_PROPERTY(QString mdi_format_list_bulleted MEMBER mdi_format_list_bulleted CONSTANT)
    Q_PROPERTY(QString mdi_format_list_bulleted_square MEMBER mdi_format_list_bulleted_square CONSTANT)
    Q_PROPERTY(QString mdi_format_list_bulleted_type MEMBER mdi_format_list_bulleted_type CONSTANT)
    Q_PROPERTY(QString mdi_format_list_checkbox MEMBER mdi_format_list_checkbox CONSTANT)
    Q_PROPERTY(QString mdi_format_list_checks MEMBER mdi_format_list_checks CONSTANT)
    Q_PROPERTY(QString mdi_format_list_numbered MEMBER mdi_format_list_numbered CONSTANT)
    Q_PROPERTY(QString mdi_format_list_numbered_rtl MEMBER mdi_format_list_numbered_rtl CONSTANT)
    Q_PROPERTY(QString mdi_format_page_break MEMBER mdi_format_page_break CONSTANT)
    Q_PROPERTY(QString mdi_format_paint MEMBER mdi_format_paint CONSTANT)
    Q_PROPERTY(QString mdi_format_paragraph MEMBER mdi_format_paragraph CONSTANT)
    Q_PROPERTY(QString mdi_format_pilcrow MEMBER mdi_format_pilcrow CONSTANT)
    Q_PROPERTY(QString mdi_format_quote_close MEMBER mdi_format_quote_close CONSTANT)
    Q_PROPERTY(QString mdi_format_quote_open MEMBER mdi_format_quote_open CONSTANT)
    Q_PROPERTY(QString mdi_format_rotate_90 MEMBER mdi_format_rotate_90 CONSTANT)
    Q_PROPERTY(QString mdi_format_section MEMBER mdi_format_section CONSTANT)
    Q_PROPERTY(QString mdi_format_size MEMBER mdi_format_size CONSTANT)
    Q_PROPERTY(QString mdi_format_strikethrough MEMBER mdi_format_strikethrough CONSTANT)
    Q_PROPERTY(QString mdi_format_strikethrough_variant MEMBER mdi_format_strikethrough_variant CONSTANT)
    Q_PROPERTY(QString mdi_format_subscript MEMBER mdi_format_subscript CONSTANT)
    Q_PROPERTY(QString mdi_format_superscript MEMBER mdi_format_superscript CONSTANT)
    Q_PROPERTY(QString mdi_format_text MEMBER mdi_format_text CONSTANT)
    Q_PROPERTY(QString mdi_format_text_rotation_down MEMBER mdi_format_text_rotation_down CONSTANT)
    Q_PROPERTY(QString mdi_format_text_rotation_none MEMBER mdi_format_text_rotation_none CONSTANT)
    Q_PROPERTY(QString mdi_format_text_wrapping_clip MEMBER mdi_format_text_wrapping_clip CONSTANT)
    Q_PROPERTY(QString mdi_format_text_wrapping_overflow MEMBER mdi_format_text_wrapping_overflow CONSTANT)
    Q_PROPERTY(QString mdi_format_text_wrapping_wrap MEMBER mdi_format_text_wrapping_wrap CONSTANT)
    Q_PROPERTY(QString mdi_format_textbox MEMBER mdi_format_textbox CONSTANT)
    Q_PROPERTY(QString mdi_format_textdirection_l_to_r MEMBER mdi_format_textdirection_l_to_r CONSTANT)
    Q_PROPERTY(QString mdi_format_textdirection_r_to_l MEMBER mdi_format_textdirection_r_to_l CONSTANT)
    Q_PROPERTY(QString mdi_format_title MEMBER mdi_format_title CONSTANT)
    Q_PROPERTY(QString mdi_format_underline MEMBER mdi_format_underline CONSTANT)
    Q_PROPERTY(QString mdi_format_vertical_align_bottom MEMBER mdi_format_vertical_align_bottom CONSTANT)
    Q_PROPERTY(QString mdi_format_vertical_align_center MEMBER mdi_format_vertical_align_center CONSTANT)
    Q_PROPERTY(QString mdi_format_vertical_align_top MEMBER mdi_format_vertical_align_top CONSTANT)
    Q_PROPERTY(QString mdi_format_wrap_inline MEMBER mdi_format_wrap_inline CONSTANT)
    Q_PROPERTY(QString mdi_format_wrap_square MEMBER mdi_format_wrap_square CONSTANT)
    Q_PROPERTY(QString mdi_format_wrap_tight MEMBER mdi_format_wrap_tight CONSTANT)
    Q_PROPERTY(QString mdi_format_wrap_top_bottom MEMBER mdi_format_wrap_top_bottom CONSTANT)
    Q_PROPERTY(QString mdi_forum MEMBER mdi_forum CONSTANT)
    Q_PROPERTY(QString mdi_forum_outline MEMBER mdi_forum_outline CONSTANT)
    Q_PROPERTY(QString mdi_forward MEMBER mdi_forward CONSTANT)
    Q_PROPERTY(QString mdi_forwardburger MEMBER mdi_forwardburger CONSTANT)
    Q_PROPERTY(QString mdi_fountain MEMBER mdi_fountain CONSTANT)
    Q_PROPERTY(QString mdi_fountain_pen MEMBER mdi_fountain_pen CONSTANT)
    Q_PROPERTY(QString mdi_fountain_pen_tip MEMBER mdi_fountain_pen_tip CONSTANT)
    Q_PROPERTY(QString mdi_foursquare MEMBER mdi_foursquare CONSTANT)
    Q_PROPERTY(QString mdi_freebsd MEMBER mdi_freebsd CONSTANT)
    Q_PROPERTY(QString mdi_fridge MEMBER mdi_fridge CONSTANT)
    Q_PROPERTY(QString mdi_fridge_bottom MEMBER mdi_fridge_bottom CONSTANT)
    Q_PROPERTY(QString mdi_fridge_outline MEMBER mdi_fridge_outline CONSTANT)
    Q_PROPERTY(QString mdi_fridge_top MEMBER mdi_fridge_top CONSTANT)
    Q_PROPERTY(QString mdi_fuel MEMBER mdi_fuel CONSTANT)
    Q_PROPERTY(QString mdi_fullscreen MEMBER mdi_fullscreen CONSTANT)
    Q_PROPERTY(QString mdi_fullscreen_exit MEMBER mdi_fullscreen_exit CONSTANT)
    Q_PROPERTY(QString mdi_function MEMBER mdi_function CONSTANT)
    Q_PROPERTY(QString mdi_function_variant MEMBER mdi_function_variant CONSTANT)
    Q_PROPERTY(QString mdi_fuse MEMBER mdi_fuse CONSTANT)
    Q_PROPERTY(QString mdi_fuse_blade MEMBER mdi_fuse_blade CONSTANT)
    Q_PROPERTY(QString mdi_gamepad MEMBER mdi_gamepad CONSTANT)
    Q_PROPERTY(QString mdi_gamepad_variant MEMBER mdi_gamepad_variant CONSTANT)
    Q_PROPERTY(QString mdi_gantry_crane MEMBER mdi_gantry_crane CONSTANT)
    Q_PROPERTY(QString mdi_garage MEMBER mdi_garage CONSTANT)
    Q_PROPERTY(QString mdi_garage_alert MEMBER mdi_garage_alert CONSTANT)
    Q_PROPERTY(QString mdi_garage_open MEMBER mdi_garage_open CONSTANT)
    Q_PROPERTY(QString mdi_gas_cylinder MEMBER mdi_gas_cylinder CONSTANT)
    Q_PROPERTY(QString mdi_gas_station MEMBER mdi_gas_station CONSTANT)
    Q_PROPERTY(QString mdi_gate MEMBER mdi_gate CONSTANT)
    Q_PROPERTY(QString mdi_gate_and MEMBER mdi_gate_and CONSTANT)
    Q_PROPERTY(QString mdi_gate_nand MEMBER mdi_gate_nand CONSTANT)
    Q_PROPERTY(QString mdi_gate_nor MEMBER mdi_gate_nor CONSTANT)
    Q_PROPERTY(QString mdi_gate_not MEMBER mdi_gate_not CONSTANT)
    Q_PROPERTY(QString mdi_gate_or MEMBER mdi_gate_or CONSTANT)
    Q_PROPERTY(QString mdi_gate_xnor MEMBER mdi_gate_xnor CONSTANT)
    Q_PROPERTY(QString mdi_gate_xor MEMBER mdi_gate_xor CONSTANT)
    Q_PROPERTY(QString mdi_gauge MEMBER mdi_gauge CONSTANT)
    Q_PROPERTY(QString mdi_gauge_empty MEMBER mdi_gauge_empty CONSTANT)
    Q_PROPERTY(QString mdi_gauge_full MEMBER mdi_gauge_full CONSTANT)
    Q_PROPERTY(QString mdi_gauge_low MEMBER mdi_gauge_low CONSTANT)
    Q_PROPERTY(QString mdi_gavel MEMBER mdi_gavel CONSTANT)
    Q_PROPERTY(QString mdi_gender_female MEMBER mdi_gender_female CONSTANT)
    Q_PROPERTY(QString mdi_gender_male MEMBER mdi_gender_male CONSTANT)
    Q_PROPERTY(QString mdi_gender_male_female MEMBER mdi_gender_male_female CONSTANT)
    Q_PROPERTY(QString mdi_gender_transgender MEMBER mdi_gender_transgender CONSTANT)
    Q_PROPERTY(QString mdi_gentoo MEMBER mdi_gentoo CONSTANT)
    Q_PROPERTY(QString mdi_gesture MEMBER mdi_gesture CONSTANT)
    Q_PROPERTY(QString mdi_gesture_double_tap MEMBER mdi_gesture_double_tap CONSTANT)
    Q_PROPERTY(QString mdi_gesture_pinch MEMBER mdi_gesture_pinch CONSTANT)
    Q_PROPERTY(QString mdi_gesture_spread MEMBER mdi_gesture_spread CONSTANT)
    Q_PROPERTY(QString mdi_gesture_swipe MEMBER mdi_gesture_swipe CONSTANT)
    Q_PROPERTY(QString mdi_gesture_swipe_down MEMBER mdi_gesture_swipe_down CONSTANT)
    Q_PROPERTY(QString mdi_gesture_swipe_horizontal MEMBER mdi_gesture_swipe_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_gesture_swipe_left MEMBER mdi_gesture_swipe_left CONSTANT)
    Q_PROPERTY(QString mdi_gesture_swipe_right MEMBER mdi_gesture_swipe_right CONSTANT)
    Q_PROPERTY(QString mdi_gesture_swipe_up MEMBER mdi_gesture_swipe_up CONSTANT)
    Q_PROPERTY(QString mdi_gesture_swipe_vertical MEMBER mdi_gesture_swipe_vertical CONSTANT)
    Q_PROPERTY(QString mdi_gesture_tap MEMBER mdi_gesture_tap CONSTANT)
    Q_PROPERTY(QString mdi_gesture_tap_hold MEMBER mdi_gesture_tap_hold CONSTANT)
    Q_PROPERTY(QString mdi_gesture_two_double_tap MEMBER mdi_gesture_two_double_tap CONSTANT)
    Q_PROPERTY(QString mdi_gesture_two_tap MEMBER mdi_gesture_two_tap CONSTANT)
    Q_PROPERTY(QString mdi_ghost MEMBER mdi_ghost CONSTANT)
    Q_PROPERTY(QString mdi_ghost_off MEMBER mdi_ghost_off CONSTANT)
    Q_PROPERTY(QString mdi_gif MEMBER mdi_gif CONSTANT)
    Q_PROPERTY(QString mdi_gift MEMBER mdi_gift CONSTANT)
    Q_PROPERTY(QString mdi_git MEMBER mdi_git CONSTANT)
    Q_PROPERTY(QString mdi_github_box MEMBER mdi_github_box CONSTANT)
    Q_PROPERTY(QString mdi_github_circle MEMBER mdi_github_circle CONSTANT)
    Q_PROPERTY(QString mdi_github_face MEMBER mdi_github_face CONSTANT)
    Q_PROPERTY(QString mdi_gitlab MEMBER mdi_gitlab CONSTANT)
    Q_PROPERTY(QString mdi_glass_cocktail MEMBER mdi_glass_cocktail CONSTANT)
    Q_PROPERTY(QString mdi_glass_flute MEMBER mdi_glass_flute CONSTANT)
    Q_PROPERTY(QString mdi_glass_mug MEMBER mdi_glass_mug CONSTANT)
    Q_PROPERTY(QString mdi_glass_stange MEMBER mdi_glass_stange CONSTANT)
    Q_PROPERTY(QString mdi_glass_tulip MEMBER mdi_glass_tulip CONSTANT)
    Q_PROPERTY(QString mdi_glass_wine MEMBER mdi_glass_wine CONSTANT)
    Q_PROPERTY(QString mdi_glassdoor MEMBER mdi_glassdoor CONSTANT)
    Q_PROPERTY(QString mdi_glasses MEMBER mdi_glasses CONSTANT)
    Q_PROPERTY(QString mdi_globe_model MEMBER mdi_globe_model CONSTANT)
    Q_PROPERTY(QString mdi_gmail MEMBER mdi_gmail CONSTANT)
    Q_PROPERTY(QString mdi_gnome MEMBER mdi_gnome CONSTANT)
    Q_PROPERTY(QString mdi_go_kart MEMBER mdi_go_kart CONSTANT)
    Q_PROPERTY(QString mdi_go_kart_track MEMBER mdi_go_kart_track CONSTANT)
    Q_PROPERTY(QString mdi_gog MEMBER mdi_gog CONSTANT)
    Q_PROPERTY(QString mdi_golf MEMBER mdi_golf CONSTANT)
    Q_PROPERTY(QString mdi_gondola MEMBER mdi_gondola CONSTANT)
    Q_PROPERTY(QString mdi_goodreads MEMBER mdi_goodreads CONSTANT)
    Q_PROPERTY(QString mdi_google MEMBER mdi_google CONSTANT)
    Q_PROPERTY(QString mdi_google_adwords MEMBER mdi_google_adwords CONSTANT)
    Q_PROPERTY(QString mdi_google_allo MEMBER mdi_google_allo CONSTANT)
    Q_PROPERTY(QString mdi_google_analytics MEMBER mdi_google_analytics CONSTANT)
    Q_PROPERTY(QString mdi_google_assistant MEMBER mdi_google_assistant CONSTANT)
    Q_PROPERTY(QString mdi_google_cardboard MEMBER mdi_google_cardboard CONSTANT)
    Q_PROPERTY(QString mdi_google_chrome MEMBER mdi_google_chrome CONSTANT)
    Q_PROPERTY(QString mdi_google_circles MEMBER mdi_google_circles CONSTANT)
    Q_PROPERTY(QString mdi_google_circles_communities MEMBER mdi_google_circles_communities CONSTANT)
    Q_PROPERTY(QString mdi_google_circles_extended MEMBER mdi_google_circles_extended CONSTANT)
    Q_PROPERTY(QString mdi_google_circles_group MEMBER mdi_google_circles_group CONSTANT)
    Q_PROPERTY(QString mdi_google_classroom MEMBER mdi_google_classroom CONSTANT)
    Q_PROPERTY(QString mdi_google_controller MEMBER mdi_google_controller CONSTANT)
    Q_PROPERTY(QString mdi_google_controller_off MEMBER mdi_google_controller_off CONSTANT)
    Q_PROPERTY(QString mdi_google_drive MEMBER mdi_google_drive CONSTANT)
    Q_PROPERTY(QString mdi_google_earth MEMBER mdi_google_earth CONSTANT)
    Q_PROPERTY(QString mdi_google_fit MEMBER mdi_google_fit CONSTANT)
    Q_PROPERTY(QString mdi_google_glass MEMBER mdi_google_glass CONSTANT)
    Q_PROPERTY(QString mdi_google_hangouts MEMBER mdi_google_hangouts CONSTANT)
    Q_PROPERTY(QString mdi_google_home MEMBER mdi_google_home CONSTANT)
    Q_PROPERTY(QString mdi_google_keep MEMBER mdi_google_keep CONSTANT)
    Q_PROPERTY(QString mdi_google_lens MEMBER mdi_google_lens CONSTANT)
    Q_PROPERTY(QString mdi_google_maps MEMBER mdi_google_maps CONSTANT)
    Q_PROPERTY(QString mdi_google_nearby MEMBER mdi_google_nearby CONSTANT)
    Q_PROPERTY(QString mdi_google_pages MEMBER mdi_google_pages CONSTANT)
    Q_PROPERTY(QString mdi_google_photos MEMBER mdi_google_photos CONSTANT)
    Q_PROPERTY(QString mdi_google_physical_web MEMBER mdi_google_physical_web CONSTANT)
    Q_PROPERTY(QString mdi_google_play MEMBER mdi_google_play CONSTANT)
    Q_PROPERTY(QString mdi_google_plus MEMBER mdi_google_plus CONSTANT)
    Q_PROPERTY(QString mdi_google_plus_box MEMBER mdi_google_plus_box CONSTANT)
    Q_PROPERTY(QString mdi_google_spreadsheet MEMBER mdi_google_spreadsheet CONSTANT)
    Q_PROPERTY(QString mdi_google_street_view MEMBER mdi_google_street_view CONSTANT)
    Q_PROPERTY(QString mdi_google_translate MEMBER mdi_google_translate CONSTANT)
    Q_PROPERTY(QString mdi_gpu MEMBER mdi_gpu CONSTANT)
    Q_PROPERTY(QString mdi_gradient MEMBER mdi_gradient CONSTANT)
    Q_PROPERTY(QString mdi_grain MEMBER mdi_grain CONSTANT)
    Q_PROPERTY(QString mdi_graphql MEMBER mdi_graphql CONSTANT)
    Q_PROPERTY(QString mdi_grave_stone MEMBER mdi_grave_stone CONSTANT)
    Q_PROPERTY(QString mdi_grease_pencil MEMBER mdi_grease_pencil CONSTANT)
    Q_PROPERTY(QString mdi_greater_than MEMBER mdi_greater_than CONSTANT)
    Q_PROPERTY(QString mdi_greater_than_or_equal MEMBER mdi_greater_than_or_equal CONSTANT)
    Q_PROPERTY(QString mdi_grid MEMBER mdi_grid CONSTANT)
    Q_PROPERTY(QString mdi_grid_large MEMBER mdi_grid_large CONSTANT)
    Q_PROPERTY(QString mdi_grid_off MEMBER mdi_grid_off CONSTANT)
    Q_PROPERTY(QString mdi_group MEMBER mdi_group CONSTANT)
    Q_PROPERTY(QString mdi_guitar_acoustic MEMBER mdi_guitar_acoustic CONSTANT)
    Q_PROPERTY(QString mdi_guitar_electric MEMBER mdi_guitar_electric CONSTANT)
    Q_PROPERTY(QString mdi_guitar_pick MEMBER mdi_guitar_pick CONSTANT)
    Q_PROPERTY(QString mdi_guitar_pick_outline MEMBER mdi_guitar_pick_outline CONSTANT)
    Q_PROPERTY(QString mdi_guy_fawkes_mask MEMBER mdi_guy_fawkes_mask CONSTANT)
    Q_PROPERTY(QString mdi_hackernews MEMBER mdi_hackernews CONSTANT)
    Q_PROPERTY(QString mdi_hail MEMBER mdi_hail CONSTANT)
    Q_PROPERTY(QString mdi_halloween MEMBER mdi_halloween CONSTANT)
    Q_PROPERTY(QString mdi_hamburger MEMBER mdi_hamburger CONSTANT)
    Q_PROPERTY(QString mdi_hammer MEMBER mdi_hammer CONSTANT)
    Q_PROPERTY(QString mdi_hand MEMBER mdi_hand CONSTANT)
    Q_PROPERTY(QString mdi_hand_okay MEMBER mdi_hand_okay CONSTANT)
    Q_PROPERTY(QString mdi_hand_peace MEMBER mdi_hand_peace CONSTANT)
    Q_PROPERTY(QString mdi_hand_peace_variant MEMBER mdi_hand_peace_variant CONSTANT)
    Q_PROPERTY(QString mdi_hand_pointing_down MEMBER mdi_hand_pointing_down CONSTANT)
    Q_PROPERTY(QString mdi_hand_pointing_left MEMBER mdi_hand_pointing_left CONSTANT)
    Q_PROPERTY(QString mdi_hand_pointing_right MEMBER mdi_hand_pointing_right CONSTANT)
    Q_PROPERTY(QString mdi_hand_pointing_up MEMBER mdi_hand_pointing_up CONSTANT)
    Q_PROPERTY(QString mdi_hanger MEMBER mdi_hanger CONSTANT)
    Q_PROPERTY(QString mdi_hard_hat MEMBER mdi_hard_hat CONSTANT)
    Q_PROPERTY(QString mdi_harddisk MEMBER mdi_harddisk CONSTANT)
    Q_PROPERTY(QString mdi_hat_fedora MEMBER mdi_hat_fedora CONSTANT)
    Q_PROPERTY(QString mdi_hazard_lights MEMBER mdi_hazard_lights CONSTANT)
    Q_PROPERTY(QString mdi_hdr MEMBER mdi_hdr CONSTANT)
    Q_PROPERTY(QString mdi_hdr_off MEMBER mdi_hdr_off CONSTANT)
    Q_PROPERTY(QString mdi_headphones MEMBER mdi_headphones CONSTANT)
    Q_PROPERTY(QString mdi_headphones_bluetooth MEMBER mdi_headphones_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_headphones_box MEMBER mdi_headphones_box CONSTANT)
    Q_PROPERTY(QString mdi_headphones_off MEMBER mdi_headphones_off CONSTANT)
    Q_PROPERTY(QString mdi_headphones_settings MEMBER mdi_headphones_settings CONSTANT)
    Q_PROPERTY(QString mdi_headset MEMBER mdi_headset CONSTANT)
    Q_PROPERTY(QString mdi_headset_dock MEMBER mdi_headset_dock CONSTANT)
    Q_PROPERTY(QString mdi_headset_off MEMBER mdi_headset_off CONSTANT)
    Q_PROPERTY(QString mdi_heart MEMBER mdi_heart CONSTANT)
    Q_PROPERTY(QString mdi_heart_box MEMBER mdi_heart_box CONSTANT)
    Q_PROPERTY(QString mdi_heart_box_outline MEMBER mdi_heart_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_heart_broken MEMBER mdi_heart_broken CONSTANT)
    Q_PROPERTY(QString mdi_heart_broken_outline MEMBER mdi_heart_broken_outline CONSTANT)
    Q_PROPERTY(QString mdi_heart_circle MEMBER mdi_heart_circle CONSTANT)
    Q_PROPERTY(QString mdi_heart_circle_outline MEMBER mdi_heart_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_heart_half MEMBER mdi_heart_half CONSTANT)
    Q_PROPERTY(QString mdi_heart_half_full MEMBER mdi_heart_half_full CONSTANT)
    Q_PROPERTY(QString mdi_heart_half_outline MEMBER mdi_heart_half_outline CONSTANT)
    Q_PROPERTY(QString mdi_heart_multiple MEMBER mdi_heart_multiple CONSTANT)
    Q_PROPERTY(QString mdi_heart_multiple_outline MEMBER mdi_heart_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_heart_off MEMBER mdi_heart_off CONSTANT)
    Q_PROPERTY(QString mdi_heart_outline MEMBER mdi_heart_outline CONSTANT)
    Q_PROPERTY(QString mdi_heart_pulse MEMBER mdi_heart_pulse CONSTANT)
    Q_PROPERTY(QString mdi_helicopter MEMBER mdi_helicopter CONSTANT)
    Q_PROPERTY(QString mdi_help MEMBER mdi_help CONSTANT)
    Q_PROPERTY(QString mdi_help_box MEMBER mdi_help_box CONSTANT)
    Q_PROPERTY(QString mdi_help_circle MEMBER mdi_help_circle CONSTANT)
    Q_PROPERTY(QString mdi_help_circle_outline MEMBER mdi_help_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_help_network MEMBER mdi_help_network CONSTANT)
    Q_PROPERTY(QString mdi_help_network_outline MEMBER mdi_help_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_help_rhombus MEMBER mdi_help_rhombus CONSTANT)
    Q_PROPERTY(QString mdi_help_rhombus_outline MEMBER mdi_help_rhombus_outline CONSTANT)
    Q_PROPERTY(QString mdi_hexagon MEMBER mdi_hexagon CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_multiple MEMBER mdi_hexagon_multiple CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_outline MEMBER mdi_hexagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_slice_1 MEMBER mdi_hexagon_slice_1 CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_slice_2 MEMBER mdi_hexagon_slice_2 CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_slice_3 MEMBER mdi_hexagon_slice_3 CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_slice_4 MEMBER mdi_hexagon_slice_4 CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_slice_5 MEMBER mdi_hexagon_slice_5 CONSTANT)
    Q_PROPERTY(QString mdi_hexagon_slice_6 MEMBER mdi_hexagon_slice_6 CONSTANT)
    Q_PROPERTY(QString mdi_hexagram MEMBER mdi_hexagram CONSTANT)
    Q_PROPERTY(QString mdi_hexagram_outline MEMBER mdi_hexagram_outline CONSTANT)
    Q_PROPERTY(QString mdi_high_definition MEMBER mdi_high_definition CONSTANT)
    Q_PROPERTY(QString mdi_high_definition_box MEMBER mdi_high_definition_box CONSTANT)
    Q_PROPERTY(QString mdi_highway MEMBER mdi_highway CONSTANT)
    Q_PROPERTY(QString mdi_hiking MEMBER mdi_hiking CONSTANT)
    Q_PROPERTY(QString mdi_hinduism MEMBER mdi_hinduism CONSTANT)
    Q_PROPERTY(QString mdi_history MEMBER mdi_history CONSTANT)
    Q_PROPERTY(QString mdi_hockey_puck MEMBER mdi_hockey_puck CONSTANT)
    Q_PROPERTY(QString mdi_hockey_sticks MEMBER mdi_hockey_sticks CONSTANT)
    Q_PROPERTY(QString mdi_hololens MEMBER mdi_hololens CONSTANT)
    Q_PROPERTY(QString mdi_home MEMBER mdi_home CONSTANT)
    Q_PROPERTY(QString mdi_home_account MEMBER mdi_home_account CONSTANT)
    Q_PROPERTY(QString mdi_home_alert MEMBER mdi_home_alert CONSTANT)
    Q_PROPERTY(QString mdi_home_assistant MEMBER mdi_home_assistant CONSTANT)
    Q_PROPERTY(QString mdi_home_automation MEMBER mdi_home_automation CONSTANT)
    Q_PROPERTY(QString mdi_home_circle MEMBER mdi_home_circle CONSTANT)
    Q_PROPERTY(QString mdi_home_city MEMBER mdi_home_city CONSTANT)
    Q_PROPERTY(QString mdi_home_city_outline MEMBER mdi_home_city_outline CONSTANT)
    Q_PROPERTY(QString mdi_home_currency_usd MEMBER mdi_home_currency_usd CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_0 MEMBER mdi_home_floor_0 CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_1 MEMBER mdi_home_floor_1 CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_2 MEMBER mdi_home_floor_2 CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_3 MEMBER mdi_home_floor_3 CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_a MEMBER mdi_home_floor_a CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_b MEMBER mdi_home_floor_b CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_g MEMBER mdi_home_floor_g CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_l MEMBER mdi_home_floor_l CONSTANT)
    Q_PROPERTY(QString mdi_home_floor_negative_1 MEMBER mdi_home_floor_negative_1 CONSTANT)
    Q_PROPERTY(QString mdi_home_group MEMBER mdi_home_group CONSTANT)
    Q_PROPERTY(QString mdi_home_heart MEMBER mdi_home_heart CONSTANT)
    Q_PROPERTY(QString mdi_home_lock MEMBER mdi_home_lock CONSTANT)
    Q_PROPERTY(QString mdi_home_lock_open MEMBER mdi_home_lock_open CONSTANT)
    Q_PROPERTY(QString mdi_home_map_marker MEMBER mdi_home_map_marker CONSTANT)
    Q_PROPERTY(QString mdi_home_minus MEMBER mdi_home_minus CONSTANT)
    Q_PROPERTY(QString mdi_home_modern MEMBER mdi_home_modern CONSTANT)
    Q_PROPERTY(QString mdi_home_outline MEMBER mdi_home_outline CONSTANT)
    Q_PROPERTY(QString mdi_home_plus MEMBER mdi_home_plus CONSTANT)
    Q_PROPERTY(QString mdi_home_variant MEMBER mdi_home_variant CONSTANT)
    Q_PROPERTY(QString mdi_home_variant_outline MEMBER mdi_home_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_hook MEMBER mdi_hook CONSTANT)
    Q_PROPERTY(QString mdi_hook_off MEMBER mdi_hook_off CONSTANT)
    Q_PROPERTY(QString mdi_hops MEMBER mdi_hops CONSTANT)
    Q_PROPERTY(QString mdi_horseshoe MEMBER mdi_horseshoe CONSTANT)
    Q_PROPERTY(QString mdi_hospital MEMBER mdi_hospital CONSTANT)
    Q_PROPERTY(QString mdi_hospital_building MEMBER mdi_hospital_building CONSTANT)
    Q_PROPERTY(QString mdi_hospital_marker MEMBER mdi_hospital_marker CONSTANT)
    Q_PROPERTY(QString mdi_hot_tub MEMBER mdi_hot_tub CONSTANT)
    Q_PROPERTY(QString mdi_hotel MEMBER mdi_hotel CONSTANT)
    Q_PROPERTY(QString mdi_houzz MEMBER mdi_houzz CONSTANT)
    Q_PROPERTY(QString mdi_houzz_box MEMBER mdi_houzz_box CONSTANT)
    Q_PROPERTY(QString mdi_hubspot MEMBER mdi_hubspot CONSTANT)
    Q_PROPERTY(QString mdi_hulu MEMBER mdi_hulu CONSTANT)
    Q_PROPERTY(QString mdi_human MEMBER mdi_human CONSTANT)
    Q_PROPERTY(QString mdi_human_child MEMBER mdi_human_child CONSTANT)
    Q_PROPERTY(QString mdi_human_female MEMBER mdi_human_female CONSTANT)
    Q_PROPERTY(QString mdi_human_female_boy MEMBER mdi_human_female_boy CONSTANT)
    Q_PROPERTY(QString mdi_human_female_female MEMBER mdi_human_female_female CONSTANT)
    Q_PROPERTY(QString mdi_human_female_girl MEMBER mdi_human_female_girl CONSTANT)
    Q_PROPERTY(QString mdi_human_greeting MEMBER mdi_human_greeting CONSTANT)
    Q_PROPERTY(QString mdi_human_handsdown MEMBER mdi_human_handsdown CONSTANT)
    Q_PROPERTY(QString mdi_human_handsup MEMBER mdi_human_handsup CONSTANT)
    Q_PROPERTY(QString mdi_human_male MEMBER mdi_human_male CONSTANT)
    Q_PROPERTY(QString mdi_human_male_boy MEMBER mdi_human_male_boy CONSTANT)
    Q_PROPERTY(QString mdi_human_male_female MEMBER mdi_human_male_female CONSTANT)
    Q_PROPERTY(QString mdi_human_male_girl MEMBER mdi_human_male_girl CONSTANT)
    Q_PROPERTY(QString mdi_human_male_male MEMBER mdi_human_male_male CONSTANT)
    Q_PROPERTY(QString mdi_human_pregnant MEMBER mdi_human_pregnant CONSTANT)
    Q_PROPERTY(QString mdi_humble_bundle MEMBER mdi_humble_bundle CONSTANT)
    Q_PROPERTY(QString mdi_ice_cream MEMBER mdi_ice_cream CONSTANT)
    Q_PROPERTY(QString mdi_iframe MEMBER mdi_iframe CONSTANT)
    Q_PROPERTY(QString mdi_iframe_outline MEMBER mdi_iframe_outline CONSTANT)
    Q_PROPERTY(QString mdi_image MEMBER mdi_image CONSTANT)
    Q_PROPERTY(QString mdi_image_album MEMBER mdi_image_album CONSTANT)
    Q_PROPERTY(QString mdi_image_area MEMBER mdi_image_area CONSTANT)
    Q_PROPERTY(QString mdi_image_area_close MEMBER mdi_image_area_close CONSTANT)
    Q_PROPERTY(QString mdi_image_broken MEMBER mdi_image_broken CONSTANT)
    Q_PROPERTY(QString mdi_image_broken_variant MEMBER mdi_image_broken_variant CONSTANT)
    Q_PROPERTY(QString mdi_image_filter MEMBER mdi_image_filter CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_black_white MEMBER mdi_image_filter_black_white CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_center_focus MEMBER mdi_image_filter_center_focus CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_center_focus_weak MEMBER mdi_image_filter_center_focus_weak CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_drama MEMBER mdi_image_filter_drama CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_frames MEMBER mdi_image_filter_frames CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_hdr MEMBER mdi_image_filter_hdr CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_none MEMBER mdi_image_filter_none CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_tilt_shift MEMBER mdi_image_filter_tilt_shift CONSTANT)
    Q_PROPERTY(QString mdi_image_filter_vintage MEMBER mdi_image_filter_vintage CONSTANT)
    Q_PROPERTY(QString mdi_image_move MEMBER mdi_image_move CONSTANT)
    Q_PROPERTY(QString mdi_image_multiple MEMBER mdi_image_multiple CONSTANT)
    Q_PROPERTY(QString mdi_image_off MEMBER mdi_image_off CONSTANT)
    Q_PROPERTY(QString mdi_image_outline MEMBER mdi_image_outline CONSTANT)
    Q_PROPERTY(QString mdi_image_plus MEMBER mdi_image_plus CONSTANT)
    Q_PROPERTY(QString mdi_image_search MEMBER mdi_image_search CONSTANT)
    Q_PROPERTY(QString mdi_image_search_outline MEMBER mdi_image_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_image_size_select_actual MEMBER mdi_image_size_select_actual CONSTANT)
    Q_PROPERTY(QString mdi_image_size_select_large MEMBER mdi_image_size_select_large CONSTANT)
    Q_PROPERTY(QString mdi_image_size_select_small MEMBER mdi_image_size_select_small CONSTANT)
    Q_PROPERTY(QString mdi_import MEMBER mdi_import CONSTANT)
    Q_PROPERTY(QString mdi_inbox MEMBER mdi_inbox CONSTANT)
    Q_PROPERTY(QString mdi_inbox_arrow_down MEMBER mdi_inbox_arrow_down CONSTANT)
    Q_PROPERTY(QString mdi_inbox_arrow_up MEMBER mdi_inbox_arrow_up CONSTANT)
    Q_PROPERTY(QString mdi_inbox_multiple MEMBER mdi_inbox_multiple CONSTANT)
    Q_PROPERTY(QString mdi_inbox_multiple_outline MEMBER mdi_inbox_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_incognito MEMBER mdi_incognito CONSTANT)
    Q_PROPERTY(QString mdi_infinity MEMBER mdi_infinity CONSTANT)
    Q_PROPERTY(QString mdi_information MEMBER mdi_information CONSTANT)
    Q_PROPERTY(QString mdi_information_outline MEMBER mdi_information_outline CONSTANT)
    Q_PROPERTY(QString mdi_information_variant MEMBER mdi_information_variant CONSTANT)
    Q_PROPERTY(QString mdi_instagram MEMBER mdi_instagram CONSTANT)
    Q_PROPERTY(QString mdi_instapaper MEMBER mdi_instapaper CONSTANT)
    Q_PROPERTY(QString mdi_internet_explorer MEMBER mdi_internet_explorer CONSTANT)
    Q_PROPERTY(QString mdi_invert_colors MEMBER mdi_invert_colors CONSTANT)
    Q_PROPERTY(QString mdi_ip MEMBER mdi_ip CONSTANT)
    Q_PROPERTY(QString mdi_ip_network MEMBER mdi_ip_network CONSTANT)
    Q_PROPERTY(QString mdi_ip_network_outline MEMBER mdi_ip_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_ipod MEMBER mdi_ipod CONSTANT)
    Q_PROPERTY(QString mdi_islam MEMBER mdi_islam CONSTANT)
    Q_PROPERTY(QString mdi_itunes MEMBER mdi_itunes CONSTANT)
    Q_PROPERTY(QString mdi_jabber MEMBER mdi_jabber CONSTANT)
    Q_PROPERTY(QString mdi_jeepney MEMBER mdi_jeepney CONSTANT)
    Q_PROPERTY(QString mdi_jira MEMBER mdi_jira CONSTANT)
    Q_PROPERTY(QString mdi_jquery MEMBER mdi_jquery CONSTANT)
    Q_PROPERTY(QString mdi_jsfiddle MEMBER mdi_jsfiddle CONSTANT)
    Q_PROPERTY(QString mdi_json MEMBER mdi_json CONSTANT)
    Q_PROPERTY(QString mdi_judaism MEMBER mdi_judaism CONSTANT)
    Q_PROPERTY(QString mdi_kabaddi MEMBER mdi_kabaddi CONSTANT)
    Q_PROPERTY(QString mdi_karate MEMBER mdi_karate CONSTANT)
    Q_PROPERTY(QString mdi_keg MEMBER mdi_keg CONSTANT)
    Q_PROPERTY(QString mdi_kettle MEMBER mdi_kettle CONSTANT)
    Q_PROPERTY(QString mdi_key MEMBER mdi_key CONSTANT)
    Q_PROPERTY(QString mdi_key_change MEMBER mdi_key_change CONSTANT)
    Q_PROPERTY(QString mdi_key_minus MEMBER mdi_key_minus CONSTANT)
    Q_PROPERTY(QString mdi_key_outline MEMBER mdi_key_outline CONSTANT)
    Q_PROPERTY(QString mdi_key_plus MEMBER mdi_key_plus CONSTANT)
    Q_PROPERTY(QString mdi_key_remove MEMBER mdi_key_remove CONSTANT)
    Q_PROPERTY(QString mdi_key_variant MEMBER mdi_key_variant CONSTANT)
    Q_PROPERTY(QString mdi_keyboard MEMBER mdi_keyboard CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_backspace MEMBER mdi_keyboard_backspace CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_caps MEMBER mdi_keyboard_caps CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_close MEMBER mdi_keyboard_close CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_off MEMBER mdi_keyboard_off CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_outline MEMBER mdi_keyboard_outline CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_return MEMBER mdi_keyboard_return CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_settings MEMBER mdi_keyboard_settings CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_settings_outline MEMBER mdi_keyboard_settings_outline CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_tab MEMBER mdi_keyboard_tab CONSTANT)
    Q_PROPERTY(QString mdi_keyboard_variant MEMBER mdi_keyboard_variant CONSTANT)
    Q_PROPERTY(QString mdi_kickstarter MEMBER mdi_kickstarter CONSTANT)
    Q_PROPERTY(QString mdi_knife MEMBER mdi_knife CONSTANT)
    Q_PROPERTY(QString mdi_knife_military MEMBER mdi_knife_military CONSTANT)
    Q_PROPERTY(QString mdi_kodi MEMBER mdi_kodi CONSTANT)
    Q_PROPERTY(QString mdi_label MEMBER mdi_label CONSTANT)
    Q_PROPERTY(QString mdi_label_off MEMBER mdi_label_off CONSTANT)
    Q_PROPERTY(QString mdi_label_off_outline MEMBER mdi_label_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_label_outline MEMBER mdi_label_outline CONSTANT)
    Q_PROPERTY(QString mdi_label_variant MEMBER mdi_label_variant CONSTANT)
    Q_PROPERTY(QString mdi_label_variant_outline MEMBER mdi_label_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_ladybug MEMBER mdi_ladybug CONSTANT)
    Q_PROPERTY(QString mdi_lambda MEMBER mdi_lambda CONSTANT)
    Q_PROPERTY(QString mdi_lamp MEMBER mdi_lamp CONSTANT)
    Q_PROPERTY(QString mdi_lan MEMBER mdi_lan CONSTANT)
    Q_PROPERTY(QString mdi_lan_connect MEMBER mdi_lan_connect CONSTANT)
    Q_PROPERTY(QString mdi_lan_disconnect MEMBER mdi_lan_disconnect CONSTANT)
    Q_PROPERTY(QString mdi_lan_pending MEMBER mdi_lan_pending CONSTANT)
    Q_PROPERTY(QString mdi_language_c MEMBER mdi_language_c CONSTANT)
    Q_PROPERTY(QString mdi_language_cpp MEMBER mdi_language_cpp CONSTANT)
    Q_PROPERTY(QString mdi_language_csharp MEMBER mdi_language_csharp CONSTANT)
    Q_PROPERTY(QString mdi_language_css3 MEMBER mdi_language_css3 CONSTANT)
    Q_PROPERTY(QString mdi_language_go MEMBER mdi_language_go CONSTANT)
    Q_PROPERTY(QString mdi_language_haskell MEMBER mdi_language_haskell CONSTANT)
    Q_PROPERTY(QString mdi_language_html5 MEMBER mdi_language_html5 CONSTANT)
    Q_PROPERTY(QString mdi_language_java MEMBER mdi_language_java CONSTANT)
    Q_PROPERTY(QString mdi_language_javascript MEMBER mdi_language_javascript CONSTANT)
    Q_PROPERTY(QString mdi_language_lua MEMBER mdi_language_lua CONSTANT)
    Q_PROPERTY(QString mdi_language_php MEMBER mdi_language_php CONSTANT)
    Q_PROPERTY(QString mdi_language_python MEMBER mdi_language_python CONSTANT)
    Q_PROPERTY(QString mdi_language_python_text MEMBER mdi_language_python_text CONSTANT)
    Q_PROPERTY(QString mdi_language_r MEMBER mdi_language_r CONSTANT)
    Q_PROPERTY(QString mdi_language_ruby_on_rails MEMBER mdi_language_ruby_on_rails CONSTANT)
    Q_PROPERTY(QString mdi_language_swift MEMBER mdi_language_swift CONSTANT)
    Q_PROPERTY(QString mdi_language_typescript MEMBER mdi_language_typescript CONSTANT)
    Q_PROPERTY(QString mdi_laptop MEMBER mdi_laptop CONSTANT)
    Q_PROPERTY(QString mdi_laptop_chromebook MEMBER mdi_laptop_chromebook CONSTANT)
    Q_PROPERTY(QString mdi_laptop_mac MEMBER mdi_laptop_mac CONSTANT)
    Q_PROPERTY(QString mdi_laptop_off MEMBER mdi_laptop_off CONSTANT)
    Q_PROPERTY(QString mdi_laptop_windows MEMBER mdi_laptop_windows CONSTANT)
    Q_PROPERTY(QString mdi_laravel MEMBER mdi_laravel CONSTANT)
    Q_PROPERTY(QString mdi_lastfm MEMBER mdi_lastfm CONSTANT)
    Q_PROPERTY(QString mdi_lastpass MEMBER mdi_lastpass CONSTANT)
    Q_PROPERTY(QString mdi_launch MEMBER mdi_launch CONSTANT)
    Q_PROPERTY(QString mdi_lava_lamp MEMBER mdi_lava_lamp CONSTANT)
    Q_PROPERTY(QString mdi_layers MEMBER mdi_layers CONSTANT)
    Q_PROPERTY(QString mdi_layers_off MEMBER mdi_layers_off CONSTANT)
    Q_PROPERTY(QString mdi_layers_off_outline MEMBER mdi_layers_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_layers_outline MEMBER mdi_layers_outline CONSTANT)
    Q_PROPERTY(QString mdi_lead_pencil MEMBER mdi_lead_pencil CONSTANT)
    Q_PROPERTY(QString mdi_leaf MEMBER mdi_leaf CONSTANT)
    Q_PROPERTY(QString mdi_leaf_maple MEMBER mdi_leaf_maple CONSTANT)
    Q_PROPERTY(QString mdi_leak MEMBER mdi_leak CONSTANT)
    Q_PROPERTY(QString mdi_leak_off MEMBER mdi_leak_off CONSTANT)
    Q_PROPERTY(QString mdi_led_off MEMBER mdi_led_off CONSTANT)
    Q_PROPERTY(QString mdi_led_on MEMBER mdi_led_on CONSTANT)
    Q_PROPERTY(QString mdi_led_outline MEMBER mdi_led_outline CONSTANT)
    Q_PROPERTY(QString mdi_led_strip MEMBER mdi_led_strip CONSTANT)
    Q_PROPERTY(QString mdi_led_variant_off MEMBER mdi_led_variant_off CONSTANT)
    Q_PROPERTY(QString mdi_led_variant_on MEMBER mdi_led_variant_on CONSTANT)
    Q_PROPERTY(QString mdi_led_variant_outline MEMBER mdi_led_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_less_than MEMBER mdi_less_than CONSTANT)
    Q_PROPERTY(QString mdi_less_than_or_equal MEMBER mdi_less_than_or_equal CONSTANT)
    Q_PROPERTY(QString mdi_library MEMBER mdi_library CONSTANT)
    Q_PROPERTY(QString mdi_library_books MEMBER mdi_library_books CONSTANT)
    Q_PROPERTY(QString mdi_library_movie MEMBER mdi_library_movie CONSTANT)
    Q_PROPERTY(QString mdi_library_music MEMBER mdi_library_music CONSTANT)
    Q_PROPERTY(QString mdi_library_plus MEMBER mdi_library_plus CONSTANT)
    Q_PROPERTY(QString mdi_library_shelves MEMBER mdi_library_shelves CONSTANT)
    Q_PROPERTY(QString mdi_library_video MEMBER mdi_library_video CONSTANT)
    Q_PROPERTY(QString mdi_lifebuoy MEMBER mdi_lifebuoy CONSTANT)
    Q_PROPERTY(QString mdi_light_switch MEMBER mdi_light_switch CONSTANT)
    Q_PROPERTY(QString mdi_lightbulb MEMBER mdi_lightbulb CONSTANT)
    Q_PROPERTY(QString mdi_lightbulb_on MEMBER mdi_lightbulb_on CONSTANT)
    Q_PROPERTY(QString mdi_lightbulb_on_outline MEMBER mdi_lightbulb_on_outline CONSTANT)
    Q_PROPERTY(QString mdi_lightbulb_outline MEMBER mdi_lightbulb_outline CONSTANT)
    Q_PROPERTY(QString mdi_lighthouse MEMBER mdi_lighthouse CONSTANT)
    Q_PROPERTY(QString mdi_lighthouse_on MEMBER mdi_lighthouse_on CONSTANT)
    Q_PROPERTY(QString mdi_link MEMBER mdi_link CONSTANT)
    Q_PROPERTY(QString mdi_link_box MEMBER mdi_link_box CONSTANT)
    Q_PROPERTY(QString mdi_link_box_outline MEMBER mdi_link_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_link_box_variant MEMBER mdi_link_box_variant CONSTANT)
    Q_PROPERTY(QString mdi_link_box_variant_outline MEMBER mdi_link_box_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_link_off MEMBER mdi_link_off CONSTANT)
    Q_PROPERTY(QString mdi_link_plus MEMBER mdi_link_plus CONSTANT)
    Q_PROPERTY(QString mdi_link_variant MEMBER mdi_link_variant CONSTANT)
    Q_PROPERTY(QString mdi_link_variant_off MEMBER mdi_link_variant_off CONSTANT)
    Q_PROPERTY(QString mdi_linkedin MEMBER mdi_linkedin CONSTANT)
    Q_PROPERTY(QString mdi_linkedin_box MEMBER mdi_linkedin_box CONSTANT)
    Q_PROPERTY(QString mdi_linux MEMBER mdi_linux CONSTANT)
    Q_PROPERTY(QString mdi_linux_mint MEMBER mdi_linux_mint CONSTANT)
    Q_PROPERTY(QString mdi_litecoin MEMBER mdi_litecoin CONSTANT)
    Q_PROPERTY(QString mdi_loading MEMBER mdi_loading CONSTANT)
    Q_PROPERTY(QString mdi_lock MEMBER mdi_lock CONSTANT)
    Q_PROPERTY(QString mdi_lock_alert MEMBER mdi_lock_alert CONSTANT)
    Q_PROPERTY(QString mdi_lock_clock MEMBER mdi_lock_clock CONSTANT)
    Q_PROPERTY(QString mdi_lock_open MEMBER mdi_lock_open CONSTANT)
    Q_PROPERTY(QString mdi_lock_open_outline MEMBER mdi_lock_open_outline CONSTANT)
    Q_PROPERTY(QString mdi_lock_outline MEMBER mdi_lock_outline CONSTANT)
    Q_PROPERTY(QString mdi_lock_pattern MEMBER mdi_lock_pattern CONSTANT)
    Q_PROPERTY(QString mdi_lock_plus MEMBER mdi_lock_plus CONSTANT)
    Q_PROPERTY(QString mdi_lock_question MEMBER mdi_lock_question CONSTANT)
    Q_PROPERTY(QString mdi_lock_reset MEMBER mdi_lock_reset CONSTANT)
    Q_PROPERTY(QString mdi_lock_smart MEMBER mdi_lock_smart CONSTANT)
    Q_PROPERTY(QString mdi_locker MEMBER mdi_locker CONSTANT)
    Q_PROPERTY(QString mdi_locker_multiple MEMBER mdi_locker_multiple CONSTANT)
    Q_PROPERTY(QString mdi_login MEMBER mdi_login CONSTANT)
    Q_PROPERTY(QString mdi_login_variant MEMBER mdi_login_variant CONSTANT)
    Q_PROPERTY(QString mdi_logout MEMBER mdi_logout CONSTANT)
    Q_PROPERTY(QString mdi_logout_variant MEMBER mdi_logout_variant CONSTANT)
    Q_PROPERTY(QString mdi_looks MEMBER mdi_looks CONSTANT)
    Q_PROPERTY(QString mdi_loop MEMBER mdi_loop CONSTANT)
    Q_PROPERTY(QString mdi_loupe MEMBER mdi_loupe CONSTANT)
    Q_PROPERTY(QString mdi_lumx MEMBER mdi_lumx CONSTANT)
    Q_PROPERTY(QString mdi_lyft MEMBER mdi_lyft CONSTANT)
    Q_PROPERTY(QString mdi_magnet MEMBER mdi_magnet CONSTANT)
    Q_PROPERTY(QString mdi_magnet_on MEMBER mdi_magnet_on CONSTANT)
    Q_PROPERTY(QString mdi_magnify MEMBER mdi_magnify CONSTANT)
    Q_PROPERTY(QString mdi_magnify_close MEMBER mdi_magnify_close CONSTANT)
    Q_PROPERTY(QString mdi_magnify_minus MEMBER mdi_magnify_minus CONSTANT)
    Q_PROPERTY(QString mdi_magnify_minus_cursor MEMBER mdi_magnify_minus_cursor CONSTANT)
    Q_PROPERTY(QString mdi_magnify_minus_outline MEMBER mdi_magnify_minus_outline CONSTANT)
    Q_PROPERTY(QString mdi_magnify_plus MEMBER mdi_magnify_plus CONSTANT)
    Q_PROPERTY(QString mdi_magnify_plus_cursor MEMBER mdi_magnify_plus_cursor CONSTANT)
    Q_PROPERTY(QString mdi_magnify_plus_outline MEMBER mdi_magnify_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_mail_ru MEMBER mdi_mail_ru CONSTANT)
    Q_PROPERTY(QString mdi_mailbox MEMBER mdi_mailbox CONSTANT)
    Q_PROPERTY(QString mdi_mailbox_open MEMBER mdi_mailbox_open CONSTANT)
    Q_PROPERTY(QString mdi_mailbox_open_outline MEMBER mdi_mailbox_open_outline CONSTANT)
    Q_PROPERTY(QString mdi_mailbox_open_up MEMBER mdi_mailbox_open_up CONSTANT)
    Q_PROPERTY(QString mdi_mailbox_open_up_outline MEMBER mdi_mailbox_open_up_outline CONSTANT)
    Q_PROPERTY(QString mdi_mailbox_outline MEMBER mdi_mailbox_outline CONSTANT)
    Q_PROPERTY(QString mdi_mailbox_up MEMBER mdi_mailbox_up CONSTANT)
    Q_PROPERTY(QString mdi_mailbox_up_outline MEMBER mdi_mailbox_up_outline CONSTANT)
    Q_PROPERTY(QString mdi_map MEMBER mdi_map CONSTANT)
    Q_PROPERTY(QString mdi_map_clock MEMBER mdi_map_clock CONSTANT)
    Q_PROPERTY(QString mdi_map_clock_outline MEMBER mdi_map_clock_outline CONSTANT)
    Q_PROPERTY(QString mdi_map_legend MEMBER mdi_map_legend CONSTANT)
    Q_PROPERTY(QString mdi_map_marker MEMBER mdi_map_marker CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_check MEMBER mdi_map_marker_check CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_circle MEMBER mdi_map_marker_circle CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_distance MEMBER mdi_map_marker_distance CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_minus MEMBER mdi_map_marker_minus CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_multiple MEMBER mdi_map_marker_multiple CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_off MEMBER mdi_map_marker_off CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_outline MEMBER mdi_map_marker_outline CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_path MEMBER mdi_map_marker_path CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_plus MEMBER mdi_map_marker_plus CONSTANT)
    Q_PROPERTY(QString mdi_map_marker_radius MEMBER mdi_map_marker_radius CONSTANT)
    Q_PROPERTY(QString mdi_map_minus MEMBER mdi_map_minus CONSTANT)
    Q_PROPERTY(QString mdi_map_outline MEMBER mdi_map_outline CONSTANT)
    Q_PROPERTY(QString mdi_map_plus MEMBER mdi_map_plus CONSTANT)
    Q_PROPERTY(QString mdi_map_search MEMBER mdi_map_search CONSTANT)
    Q_PROPERTY(QString mdi_map_search_outline MEMBER mdi_map_search_outline CONSTANT)
    Q_PROPERTY(QString mdi_mapbox MEMBER mdi_mapbox CONSTANT)
    Q_PROPERTY(QString mdi_margin MEMBER mdi_margin CONSTANT)
    Q_PROPERTY(QString mdi_markdown MEMBER mdi_markdown CONSTANT)
    Q_PROPERTY(QString mdi_marker MEMBER mdi_marker CONSTANT)
    Q_PROPERTY(QString mdi_marker_cancel MEMBER mdi_marker_cancel CONSTANT)
    Q_PROPERTY(QString mdi_marker_check MEMBER mdi_marker_check CONSTANT)
    Q_PROPERTY(QString mdi_mastodon MEMBER mdi_mastodon CONSTANT)
    Q_PROPERTY(QString mdi_mastodon_variant MEMBER mdi_mastodon_variant CONSTANT)
    Q_PROPERTY(QString mdi_material_design MEMBER mdi_material_design CONSTANT)
    Q_PROPERTY(QString mdi_material_ui MEMBER mdi_material_ui CONSTANT)
    Q_PROPERTY(QString mdi_math_compass MEMBER mdi_math_compass CONSTANT)
    Q_PROPERTY(QString mdi_math_cos MEMBER mdi_math_cos CONSTANT)
    Q_PROPERTY(QString mdi_math_sin MEMBER mdi_math_sin CONSTANT)
    Q_PROPERTY(QString mdi_math_tan MEMBER mdi_math_tan CONSTANT)
    Q_PROPERTY(QString mdi_matrix MEMBER mdi_matrix CONSTANT)
    Q_PROPERTY(QString mdi_maxcdn MEMBER mdi_maxcdn CONSTANT)
    Q_PROPERTY(QString mdi_medal MEMBER mdi_medal CONSTANT)
    Q_PROPERTY(QString mdi_medical_bag MEMBER mdi_medical_bag CONSTANT)
    Q_PROPERTY(QString mdi_medium MEMBER mdi_medium CONSTANT)
    Q_PROPERTY(QString mdi_meetup MEMBER mdi_meetup CONSTANT)
    Q_PROPERTY(QString mdi_memory MEMBER mdi_memory CONSTANT)
    Q_PROPERTY(QString mdi_menu MEMBER mdi_menu CONSTANT)
    Q_PROPERTY(QString mdi_menu_down MEMBER mdi_menu_down CONSTANT)
    Q_PROPERTY(QString mdi_menu_down_outline MEMBER mdi_menu_down_outline CONSTANT)
    Q_PROPERTY(QString mdi_menu_left MEMBER mdi_menu_left CONSTANT)
    Q_PROPERTY(QString mdi_menu_left_outline MEMBER mdi_menu_left_outline CONSTANT)
    Q_PROPERTY(QString mdi_menu_open MEMBER mdi_menu_open CONSTANT)
    Q_PROPERTY(QString mdi_menu_right MEMBER mdi_menu_right CONSTANT)
    Q_PROPERTY(QString mdi_menu_right_outline MEMBER mdi_menu_right_outline CONSTANT)
    Q_PROPERTY(QString mdi_menu_swap MEMBER mdi_menu_swap CONSTANT)
    Q_PROPERTY(QString mdi_menu_swap_outline MEMBER mdi_menu_swap_outline CONSTANT)
    Q_PROPERTY(QString mdi_menu_up MEMBER mdi_menu_up CONSTANT)
    Q_PROPERTY(QString mdi_menu_up_outline MEMBER mdi_menu_up_outline CONSTANT)
    Q_PROPERTY(QString mdi_message MEMBER mdi_message CONSTANT)
    Q_PROPERTY(QString mdi_message_alert MEMBER mdi_message_alert CONSTANT)
    Q_PROPERTY(QString mdi_message_alert_outline MEMBER mdi_message_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_message_bulleted MEMBER mdi_message_bulleted CONSTANT)
    Q_PROPERTY(QString mdi_message_bulleted_off MEMBER mdi_message_bulleted_off CONSTANT)
    Q_PROPERTY(QString mdi_message_draw MEMBER mdi_message_draw CONSTANT)
    Q_PROPERTY(QString mdi_message_image MEMBER mdi_message_image CONSTANT)
    Q_PROPERTY(QString mdi_message_outline MEMBER mdi_message_outline CONSTANT)
    Q_PROPERTY(QString mdi_message_plus MEMBER mdi_message_plus CONSTANT)
    Q_PROPERTY(QString mdi_message_processing MEMBER mdi_message_processing CONSTANT)
    Q_PROPERTY(QString mdi_message_reply MEMBER mdi_message_reply CONSTANT)
    Q_PROPERTY(QString mdi_message_reply_text MEMBER mdi_message_reply_text CONSTANT)
    Q_PROPERTY(QString mdi_message_settings MEMBER mdi_message_settings CONSTANT)
    Q_PROPERTY(QString mdi_message_settings_variant MEMBER mdi_message_settings_variant CONSTANT)
    Q_PROPERTY(QString mdi_message_text MEMBER mdi_message_text CONSTANT)
    Q_PROPERTY(QString mdi_message_text_outline MEMBER mdi_message_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_message_video MEMBER mdi_message_video CONSTANT)
    Q_PROPERTY(QString mdi_meteor MEMBER mdi_meteor CONSTANT)
    Q_PROPERTY(QString mdi_metronome MEMBER mdi_metronome CONSTANT)
    Q_PROPERTY(QString mdi_metronome_tick MEMBER mdi_metronome_tick CONSTANT)
    Q_PROPERTY(QString mdi_micro_sd MEMBER mdi_micro_sd CONSTANT)
    Q_PROPERTY(QString mdi_microphone MEMBER mdi_microphone CONSTANT)
    Q_PROPERTY(QString mdi_microphone_minus MEMBER mdi_microphone_minus CONSTANT)
    Q_PROPERTY(QString mdi_microphone_off MEMBER mdi_microphone_off CONSTANT)
    Q_PROPERTY(QString mdi_microphone_outline MEMBER mdi_microphone_outline CONSTANT)
    Q_PROPERTY(QString mdi_microphone_plus MEMBER mdi_microphone_plus CONSTANT)
    Q_PROPERTY(QString mdi_microphone_settings MEMBER mdi_microphone_settings CONSTANT)
    Q_PROPERTY(QString mdi_microphone_variant MEMBER mdi_microphone_variant CONSTANT)
    Q_PROPERTY(QString mdi_microphone_variant_off MEMBER mdi_microphone_variant_off CONSTANT)
    Q_PROPERTY(QString mdi_microscope MEMBER mdi_microscope CONSTANT)
    Q_PROPERTY(QString mdi_microsoft MEMBER mdi_microsoft CONSTANT)
    Q_PROPERTY(QString mdi_microsoft_dynamics MEMBER mdi_microsoft_dynamics CONSTANT)
    Q_PROPERTY(QString mdi_microwave MEMBER mdi_microwave CONSTANT)
    Q_PROPERTY(QString mdi_midi MEMBER mdi_midi CONSTANT)
    Q_PROPERTY(QString mdi_midi_port MEMBER mdi_midi_port CONSTANT)
    Q_PROPERTY(QString mdi_mine MEMBER mdi_mine CONSTANT)
    Q_PROPERTY(QString mdi_minecraft MEMBER mdi_minecraft CONSTANT)
    Q_PROPERTY(QString mdi_mini_sd MEMBER mdi_mini_sd CONSTANT)
    Q_PROPERTY(QString mdi_minidisc MEMBER mdi_minidisc CONSTANT)
    Q_PROPERTY(QString mdi_minus MEMBER mdi_minus CONSTANT)
    Q_PROPERTY(QString mdi_minus_box MEMBER mdi_minus_box CONSTANT)
    Q_PROPERTY(QString mdi_minus_box_outline MEMBER mdi_minus_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_minus_circle MEMBER mdi_minus_circle CONSTANT)
    Q_PROPERTY(QString mdi_minus_circle_outline MEMBER mdi_minus_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_minus_network MEMBER mdi_minus_network CONSTANT)
    Q_PROPERTY(QString mdi_minus_network_outline MEMBER mdi_minus_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_mixcloud MEMBER mdi_mixcloud CONSTANT)
    Q_PROPERTY(QString mdi_mixed_martial_arts MEMBER mdi_mixed_martial_arts CONSTANT)
    Q_PROPERTY(QString mdi_mixed_reality MEMBER mdi_mixed_reality CONSTANT)
    Q_PROPERTY(QString mdi_mixer MEMBER mdi_mixer CONSTANT)
    Q_PROPERTY(QString mdi_molecule MEMBER mdi_molecule CONSTANT)
    Q_PROPERTY(QString mdi_monitor MEMBER mdi_monitor CONSTANT)
    Q_PROPERTY(QString mdi_monitor_cellphone MEMBER mdi_monitor_cellphone CONSTANT)
    Q_PROPERTY(QString mdi_monitor_cellphone_star MEMBER mdi_monitor_cellphone_star CONSTANT)
    Q_PROPERTY(QString mdi_monitor_dashboard MEMBER mdi_monitor_dashboard CONSTANT)
    Q_PROPERTY(QString mdi_monitor_lock MEMBER mdi_monitor_lock CONSTANT)
    Q_PROPERTY(QString mdi_monitor_multiple MEMBER mdi_monitor_multiple CONSTANT)
    Q_PROPERTY(QString mdi_monitor_off MEMBER mdi_monitor_off CONSTANT)
    Q_PROPERTY(QString mdi_monitor_star MEMBER mdi_monitor_star CONSTANT)
    Q_PROPERTY(QString mdi_more MEMBER mdi_more CONSTANT)
    Q_PROPERTY(QString mdi_mother_nurse MEMBER mdi_mother_nurse CONSTANT)
    Q_PROPERTY(QString mdi_motion_sensor MEMBER mdi_motion_sensor CONSTANT)
    Q_PROPERTY(QString mdi_motorbike MEMBER mdi_motorbike CONSTANT)
    Q_PROPERTY(QString mdi_mouse MEMBER mdi_mouse CONSTANT)
    Q_PROPERTY(QString mdi_mouse_bluetooth MEMBER mdi_mouse_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_mouse_off MEMBER mdi_mouse_off CONSTANT)
    Q_PROPERTY(QString mdi_mouse_variant MEMBER mdi_mouse_variant CONSTANT)
    Q_PROPERTY(QString mdi_mouse_variant_off MEMBER mdi_mouse_variant_off CONSTANT)
    Q_PROPERTY(QString mdi_move_resize MEMBER mdi_move_resize CONSTANT)
    Q_PROPERTY(QString mdi_move_resize_variant MEMBER mdi_move_resize_variant CONSTANT)
    Q_PROPERTY(QString mdi_movie MEMBER mdi_movie CONSTANT)
    Q_PROPERTY(QString mdi_movie_outline MEMBER mdi_movie_outline CONSTANT)
    Q_PROPERTY(QString mdi_movie_roll MEMBER mdi_movie_roll CONSTANT)
    Q_PROPERTY(QString mdi_muffin MEMBER mdi_muffin CONSTANT)
    Q_PROPERTY(QString mdi_multiplication MEMBER mdi_multiplication CONSTANT)
    Q_PROPERTY(QString mdi_multiplication_box MEMBER mdi_multiplication_box CONSTANT)
    Q_PROPERTY(QString mdi_mushroom MEMBER mdi_mushroom CONSTANT)
    Q_PROPERTY(QString mdi_mushroom_outline MEMBER mdi_mushroom_outline CONSTANT)
    Q_PROPERTY(QString mdi_music MEMBER mdi_music CONSTANT)
    Q_PROPERTY(QString mdi_music_box MEMBER mdi_music_box CONSTANT)
    Q_PROPERTY(QString mdi_music_box_outline MEMBER mdi_music_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_music_circle MEMBER mdi_music_circle CONSTANT)
    Q_PROPERTY(QString mdi_music_circle_outline MEMBER mdi_music_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_music_note MEMBER mdi_music_note CONSTANT)
    Q_PROPERTY(QString mdi_music_note_bluetooth MEMBER mdi_music_note_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_music_note_bluetooth_off MEMBER mdi_music_note_bluetooth_off CONSTANT)
    Q_PROPERTY(QString mdi_music_note_eighth MEMBER mdi_music_note_eighth CONSTANT)
    Q_PROPERTY(QString mdi_music_note_half MEMBER mdi_music_note_half CONSTANT)
    Q_PROPERTY(QString mdi_music_note_off MEMBER mdi_music_note_off CONSTANT)
    Q_PROPERTY(QString mdi_music_note_plus MEMBER mdi_music_note_plus CONSTANT)
    Q_PROPERTY(QString mdi_music_note_quarter MEMBER mdi_music_note_quarter CONSTANT)
    Q_PROPERTY(QString mdi_music_note_sixteenth MEMBER mdi_music_note_sixteenth CONSTANT)
    Q_PROPERTY(QString mdi_music_note_whole MEMBER mdi_music_note_whole CONSTANT)
    Q_PROPERTY(QString mdi_music_off MEMBER mdi_music_off CONSTANT)
    Q_PROPERTY(QString mdi_nail MEMBER mdi_nail CONSTANT)
    Q_PROPERTY(QString mdi_nas MEMBER mdi_nas CONSTANT)
    Q_PROPERTY(QString mdi_nativescript MEMBER mdi_nativescript CONSTANT)
    Q_PROPERTY(QString mdi_nature MEMBER mdi_nature CONSTANT)
    Q_PROPERTY(QString mdi_nature_people MEMBER mdi_nature_people CONSTANT)
    Q_PROPERTY(QString mdi_navigation MEMBER mdi_navigation CONSTANT)
    Q_PROPERTY(QString mdi_near_me MEMBER mdi_near_me CONSTANT)
    Q_PROPERTY(QString mdi_needle MEMBER mdi_needle CONSTANT)
    Q_PROPERTY(QString mdi_netflix MEMBER mdi_netflix CONSTANT)
    Q_PROPERTY(QString mdi_network MEMBER mdi_network CONSTANT)
    Q_PROPERTY(QString mdi_network_off MEMBER mdi_network_off CONSTANT)
    Q_PROPERTY(QString mdi_network_off_outline MEMBER mdi_network_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_network_outline MEMBER mdi_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_1 MEMBER mdi_network_strength_1 CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_1_alert MEMBER mdi_network_strength_1_alert CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_2 MEMBER mdi_network_strength_2 CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_2_alert MEMBER mdi_network_strength_2_alert CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_3 MEMBER mdi_network_strength_3 CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_3_alert MEMBER mdi_network_strength_3_alert CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_4 MEMBER mdi_network_strength_4 CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_4_alert MEMBER mdi_network_strength_4_alert CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_off MEMBER mdi_network_strength_off CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_off_outline MEMBER mdi_network_strength_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_network_strength_outline MEMBER mdi_network_strength_outline CONSTANT)
    Q_PROPERTY(QString mdi_new_box MEMBER mdi_new_box CONSTANT)
    Q_PROPERTY(QString mdi_newspaper MEMBER mdi_newspaper CONSTANT)
    Q_PROPERTY(QString mdi_nfc MEMBER mdi_nfc CONSTANT)
    Q_PROPERTY(QString mdi_nfc_tap MEMBER mdi_nfc_tap CONSTANT)
    Q_PROPERTY(QString mdi_nfc_variant MEMBER mdi_nfc_variant CONSTANT)
    Q_PROPERTY(QString mdi_ninja MEMBER mdi_ninja CONSTANT)
    Q_PROPERTY(QString mdi_nintendo_switch MEMBER mdi_nintendo_switch CONSTANT)
    Q_PROPERTY(QString mdi_nodejs MEMBER mdi_nodejs CONSTANT)
    Q_PROPERTY(QString mdi_not_equal MEMBER mdi_not_equal CONSTANT)
    Q_PROPERTY(QString mdi_not_equal_variant MEMBER mdi_not_equal_variant CONSTANT)
    Q_PROPERTY(QString mdi_note MEMBER mdi_note CONSTANT)
    Q_PROPERTY(QString mdi_note_multiple MEMBER mdi_note_multiple CONSTANT)
    Q_PROPERTY(QString mdi_note_multiple_outline MEMBER mdi_note_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_note_outline MEMBER mdi_note_outline CONSTANT)
    Q_PROPERTY(QString mdi_note_plus MEMBER mdi_note_plus CONSTANT)
    Q_PROPERTY(QString mdi_note_plus_outline MEMBER mdi_note_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_note_text MEMBER mdi_note_text CONSTANT)
    Q_PROPERTY(QString mdi_notebook MEMBER mdi_notebook CONSTANT)
    Q_PROPERTY(QString mdi_notification_clear_all MEMBER mdi_notification_clear_all CONSTANT)
    Q_PROPERTY(QString mdi_npm MEMBER mdi_npm CONSTANT)
    Q_PROPERTY(QString mdi_npm_variant MEMBER mdi_npm_variant CONSTANT)
    Q_PROPERTY(QString mdi_npm_variant_outline MEMBER mdi_npm_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_nuke MEMBER mdi_nuke CONSTANT)
    Q_PROPERTY(QString mdi_null MEMBER mdi_null CONSTANT)
    Q_PROPERTY(QString mdi_numeric MEMBER mdi_numeric CONSTANT)
    Q_PROPERTY(QString mdi_numeric_0 MEMBER mdi_numeric_0 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_0_box MEMBER mdi_numeric_0_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_0_box_multiple_outline MEMBER mdi_numeric_0_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_0_box_outline MEMBER mdi_numeric_0_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_0_circle MEMBER mdi_numeric_0_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_0_circle_outline MEMBER mdi_numeric_0_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_1 MEMBER mdi_numeric_1 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_1_box MEMBER mdi_numeric_1_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_1_box_multiple_outline MEMBER mdi_numeric_1_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_1_box_outline MEMBER mdi_numeric_1_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_1_circle MEMBER mdi_numeric_1_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_1_circle_outline MEMBER mdi_numeric_1_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_2 MEMBER mdi_numeric_2 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_2_box MEMBER mdi_numeric_2_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_2_box_multiple_outline MEMBER mdi_numeric_2_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_2_box_outline MEMBER mdi_numeric_2_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_2_circle MEMBER mdi_numeric_2_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_2_circle_outline MEMBER mdi_numeric_2_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_3 MEMBER mdi_numeric_3 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_3_box MEMBER mdi_numeric_3_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_3_box_multiple_outline MEMBER mdi_numeric_3_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_3_box_outline MEMBER mdi_numeric_3_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_3_circle MEMBER mdi_numeric_3_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_3_circle_outline MEMBER mdi_numeric_3_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_4 MEMBER mdi_numeric_4 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_4_box MEMBER mdi_numeric_4_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_4_box_multiple_outline MEMBER mdi_numeric_4_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_4_box_outline MEMBER mdi_numeric_4_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_4_circle MEMBER mdi_numeric_4_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_4_circle_outline MEMBER mdi_numeric_4_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_5 MEMBER mdi_numeric_5 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_5_box MEMBER mdi_numeric_5_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_5_box_multiple_outline MEMBER mdi_numeric_5_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_5_box_outline MEMBER mdi_numeric_5_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_5_circle MEMBER mdi_numeric_5_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_5_circle_outline MEMBER mdi_numeric_5_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_6 MEMBER mdi_numeric_6 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_6_box MEMBER mdi_numeric_6_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_6_box_multiple_outline MEMBER mdi_numeric_6_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_6_box_outline MEMBER mdi_numeric_6_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_6_circle MEMBER mdi_numeric_6_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_6_circle_outline MEMBER mdi_numeric_6_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_7 MEMBER mdi_numeric_7 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_7_box MEMBER mdi_numeric_7_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_7_box_multiple_outline MEMBER mdi_numeric_7_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_7_box_outline MEMBER mdi_numeric_7_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_7_circle MEMBER mdi_numeric_7_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_7_circle_outline MEMBER mdi_numeric_7_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_8 MEMBER mdi_numeric_8 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_8_box MEMBER mdi_numeric_8_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_8_box_multiple_outline MEMBER mdi_numeric_8_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_8_box_outline MEMBER mdi_numeric_8_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_8_circle MEMBER mdi_numeric_8_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_8_circle_outline MEMBER mdi_numeric_8_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9 MEMBER mdi_numeric_9 CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_box MEMBER mdi_numeric_9_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_box_multiple_outline MEMBER mdi_numeric_9_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_box_outline MEMBER mdi_numeric_9_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_circle MEMBER mdi_numeric_9_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_circle_outline MEMBER mdi_numeric_9_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_plus_box MEMBER mdi_numeric_9_plus_box CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_plus_box_multiple_outline MEMBER mdi_numeric_9_plus_box_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_plus_box_outline MEMBER mdi_numeric_9_plus_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_plus_circle MEMBER mdi_numeric_9_plus_circle CONSTANT)
    Q_PROPERTY(QString mdi_numeric_9_plus_circle_outline MEMBER mdi_numeric_9_plus_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_nut MEMBER mdi_nut CONSTANT)
    Q_PROPERTY(QString mdi_nutrition MEMBER mdi_nutrition CONSTANT)
    Q_PROPERTY(QString mdi_oar MEMBER mdi_oar CONSTANT)
    Q_PROPERTY(QString mdi_ocarina MEMBER mdi_ocarina CONSTANT)
    Q_PROPERTY(QString mdi_octagon MEMBER mdi_octagon CONSTANT)
    Q_PROPERTY(QString mdi_octagon_outline MEMBER mdi_octagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_octagram MEMBER mdi_octagram CONSTANT)
    Q_PROPERTY(QString mdi_octagram_outline MEMBER mdi_octagram_outline CONSTANT)
    Q_PROPERTY(QString mdi_odnoklassniki MEMBER mdi_odnoklassniki CONSTANT)
    Q_PROPERTY(QString mdi_office MEMBER mdi_office CONSTANT)
    Q_PROPERTY(QString mdi_office_building MEMBER mdi_office_building CONSTANT)
    Q_PROPERTY(QString mdi_oil MEMBER mdi_oil CONSTANT)
    Q_PROPERTY(QString mdi_oil_temperature MEMBER mdi_oil_temperature CONSTANT)
    Q_PROPERTY(QString mdi_omega MEMBER mdi_omega CONSTANT)
    Q_PROPERTY(QString mdi_one_up MEMBER mdi_one_up CONSTANT)
    Q_PROPERTY(QString mdi_onedrive MEMBER mdi_onedrive CONSTANT)
    Q_PROPERTY(QString mdi_onenote MEMBER mdi_onenote CONSTANT)
    Q_PROPERTY(QString mdi_onepassword MEMBER mdi_onepassword CONSTANT)
    Q_PROPERTY(QString mdi_opacity MEMBER mdi_opacity CONSTANT)
    Q_PROPERTY(QString mdi_open_in_app MEMBER mdi_open_in_app CONSTANT)
    Q_PROPERTY(QString mdi_open_in_new MEMBER mdi_open_in_new CONSTANT)
    Q_PROPERTY(QString mdi_open_source_initiative MEMBER mdi_open_source_initiative CONSTANT)
    Q_PROPERTY(QString mdi_openid MEMBER mdi_openid CONSTANT)
    Q_PROPERTY(QString mdi_opera MEMBER mdi_opera CONSTANT)
    Q_PROPERTY(QString mdi_orbit MEMBER mdi_orbit CONSTANT)
    Q_PROPERTY(QString mdi_origin MEMBER mdi_origin CONSTANT)
    Q_PROPERTY(QString mdi_ornament MEMBER mdi_ornament CONSTANT)
    Q_PROPERTY(QString mdi_ornament_variant MEMBER mdi_ornament_variant CONSTANT)
    Q_PROPERTY(QString mdi_outlook MEMBER mdi_outlook CONSTANT)
    Q_PROPERTY(QString mdi_owl MEMBER mdi_owl CONSTANT)
    Q_PROPERTY(QString mdi_pac_man MEMBER mdi_pac_man CONSTANT)
    Q_PROPERTY(QString mdi_package MEMBER mdi_package CONSTANT)
    Q_PROPERTY(QString mdi_package_down MEMBER mdi_package_down CONSTANT)
    Q_PROPERTY(QString mdi_package_up MEMBER mdi_package_up CONSTANT)
    Q_PROPERTY(QString mdi_package_variant MEMBER mdi_package_variant CONSTANT)
    Q_PROPERTY(QString mdi_package_variant_closed MEMBER mdi_package_variant_closed CONSTANT)
    Q_PROPERTY(QString mdi_page_first MEMBER mdi_page_first CONSTANT)
    Q_PROPERTY(QString mdi_page_last MEMBER mdi_page_last CONSTANT)
    Q_PROPERTY(QString mdi_page_layout_body MEMBER mdi_page_layout_body CONSTANT)
    Q_PROPERTY(QString mdi_page_layout_footer MEMBER mdi_page_layout_footer CONSTANT)
    Q_PROPERTY(QString mdi_page_layout_header MEMBER mdi_page_layout_header CONSTANT)
    Q_PROPERTY(QString mdi_page_layout_sidebar_left MEMBER mdi_page_layout_sidebar_left CONSTANT)
    Q_PROPERTY(QString mdi_page_layout_sidebar_right MEMBER mdi_page_layout_sidebar_right CONSTANT)
    Q_PROPERTY(QString mdi_page_next MEMBER mdi_page_next CONSTANT)
    Q_PROPERTY(QString mdi_page_next_outline MEMBER mdi_page_next_outline CONSTANT)
    Q_PROPERTY(QString mdi_page_previous MEMBER mdi_page_previous CONSTANT)
    Q_PROPERTY(QString mdi_page_previous_outline MEMBER mdi_page_previous_outline CONSTANT)
    Q_PROPERTY(QString mdi_palette MEMBER mdi_palette CONSTANT)
    Q_PROPERTY(QString mdi_palette_advanced MEMBER mdi_palette_advanced CONSTANT)
    Q_PROPERTY(QString mdi_palette_swatch MEMBER mdi_palette_swatch CONSTANT)
    Q_PROPERTY(QString mdi_pan MEMBER mdi_pan CONSTANT)
    Q_PROPERTY(QString mdi_pan_bottom_left MEMBER mdi_pan_bottom_left CONSTANT)
    Q_PROPERTY(QString mdi_pan_bottom_right MEMBER mdi_pan_bottom_right CONSTANT)
    Q_PROPERTY(QString mdi_pan_down MEMBER mdi_pan_down CONSTANT)
    Q_PROPERTY(QString mdi_pan_horizontal MEMBER mdi_pan_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_pan_left MEMBER mdi_pan_left CONSTANT)
    Q_PROPERTY(QString mdi_pan_right MEMBER mdi_pan_right CONSTANT)
    Q_PROPERTY(QString mdi_pan_top_left MEMBER mdi_pan_top_left CONSTANT)
    Q_PROPERTY(QString mdi_pan_top_right MEMBER mdi_pan_top_right CONSTANT)
    Q_PROPERTY(QString mdi_pan_up MEMBER mdi_pan_up CONSTANT)
    Q_PROPERTY(QString mdi_pan_vertical MEMBER mdi_pan_vertical CONSTANT)
    Q_PROPERTY(QString mdi_panda MEMBER mdi_panda CONSTANT)
    Q_PROPERTY(QString mdi_pandora MEMBER mdi_pandora CONSTANT)
    Q_PROPERTY(QString mdi_panorama MEMBER mdi_panorama CONSTANT)
    Q_PROPERTY(QString mdi_panorama_fisheye MEMBER mdi_panorama_fisheye CONSTANT)
    Q_PROPERTY(QString mdi_panorama_horizontal MEMBER mdi_panorama_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_panorama_vertical MEMBER mdi_panorama_vertical CONSTANT)
    Q_PROPERTY(QString mdi_panorama_wide_angle MEMBER mdi_panorama_wide_angle CONSTANT)
    Q_PROPERTY(QString mdi_paper_cut_vertical MEMBER mdi_paper_cut_vertical CONSTANT)
    Q_PROPERTY(QString mdi_paperclip MEMBER mdi_paperclip CONSTANT)
    Q_PROPERTY(QString mdi_parachute MEMBER mdi_parachute CONSTANT)
    Q_PROPERTY(QString mdi_parachute_outline MEMBER mdi_parachute_outline CONSTANT)
    Q_PROPERTY(QString mdi_parking MEMBER mdi_parking CONSTANT)
    Q_PROPERTY(QString mdi_passport MEMBER mdi_passport CONSTANT)
    Q_PROPERTY(QString mdi_passport_biometric MEMBER mdi_passport_biometric CONSTANT)
    Q_PROPERTY(QString mdi_patreon MEMBER mdi_patreon CONSTANT)
    Q_PROPERTY(QString mdi_pause MEMBER mdi_pause CONSTANT)
    Q_PROPERTY(QString mdi_pause_circle MEMBER mdi_pause_circle CONSTANT)
    Q_PROPERTY(QString mdi_pause_circle_outline MEMBER mdi_pause_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_pause_octagon MEMBER mdi_pause_octagon CONSTANT)
    Q_PROPERTY(QString mdi_pause_octagon_outline MEMBER mdi_pause_octagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_paw MEMBER mdi_paw CONSTANT)
    Q_PROPERTY(QString mdi_paw_off MEMBER mdi_paw_off CONSTANT)
    Q_PROPERTY(QString mdi_paypal MEMBER mdi_paypal CONSTANT)
    Q_PROPERTY(QString mdi_peace MEMBER mdi_peace CONSTANT)
    Q_PROPERTY(QString mdi_pen MEMBER mdi_pen CONSTANT)
    Q_PROPERTY(QString mdi_pen_lock MEMBER mdi_pen_lock CONSTANT)
    Q_PROPERTY(QString mdi_pen_minus MEMBER mdi_pen_minus CONSTANT)
    Q_PROPERTY(QString mdi_pen_off MEMBER mdi_pen_off CONSTANT)
    Q_PROPERTY(QString mdi_pen_plus MEMBER mdi_pen_plus CONSTANT)
    Q_PROPERTY(QString mdi_pen_remove MEMBER mdi_pen_remove CONSTANT)
    Q_PROPERTY(QString mdi_pencil MEMBER mdi_pencil CONSTANT)
    Q_PROPERTY(QString mdi_pencil_box MEMBER mdi_pencil_box CONSTANT)
    Q_PROPERTY(QString mdi_pencil_box_outline MEMBER mdi_pencil_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_pencil_circle MEMBER mdi_pencil_circle CONSTANT)
    Q_PROPERTY(QString mdi_pencil_circle_outline MEMBER mdi_pencil_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_pencil_lock MEMBER mdi_pencil_lock CONSTANT)
    Q_PROPERTY(QString mdi_pencil_lock_outline MEMBER mdi_pencil_lock_outline CONSTANT)
    Q_PROPERTY(QString mdi_pencil_minus MEMBER mdi_pencil_minus CONSTANT)
    Q_PROPERTY(QString mdi_pencil_minus_outline MEMBER mdi_pencil_minus_outline CONSTANT)
    Q_PROPERTY(QString mdi_pencil_off MEMBER mdi_pencil_off CONSTANT)
    Q_PROPERTY(QString mdi_pencil_off_outline MEMBER mdi_pencil_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_pencil_outline MEMBER mdi_pencil_outline CONSTANT)
    Q_PROPERTY(QString mdi_pencil_plus MEMBER mdi_pencil_plus CONSTANT)
    Q_PROPERTY(QString mdi_pencil_plus_outline MEMBER mdi_pencil_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_pencil_remove MEMBER mdi_pencil_remove CONSTANT)
    Q_PROPERTY(QString mdi_pencil_remove_outline MEMBER mdi_pencil_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_pentagon MEMBER mdi_pentagon CONSTANT)
    Q_PROPERTY(QString mdi_pentagon_outline MEMBER mdi_pentagon_outline CONSTANT)
    Q_PROPERTY(QString mdi_percent MEMBER mdi_percent CONSTANT)
    Q_PROPERTY(QString mdi_periodic_table MEMBER mdi_periodic_table CONSTANT)
    Q_PROPERTY(QString mdi_periodic_table_co2 MEMBER mdi_periodic_table_co2 CONSTANT)
    Q_PROPERTY(QString mdi_periscope MEMBER mdi_periscope CONSTANT)
    Q_PROPERTY(QString mdi_perspective_less MEMBER mdi_perspective_less CONSTANT)
    Q_PROPERTY(QString mdi_perspective_more MEMBER mdi_perspective_more CONSTANT)
    Q_PROPERTY(QString mdi_pharmacy MEMBER mdi_pharmacy CONSTANT)
    Q_PROPERTY(QString mdi_phone MEMBER mdi_phone CONSTANT)
    Q_PROPERTY(QString mdi_phone_bluetooth MEMBER mdi_phone_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_phone_classic MEMBER mdi_phone_classic CONSTANT)
    Q_PROPERTY(QString mdi_phone_forward MEMBER mdi_phone_forward CONSTANT)
    Q_PROPERTY(QString mdi_phone_hangup MEMBER mdi_phone_hangup CONSTANT)
    Q_PROPERTY(QString mdi_phone_in_talk MEMBER mdi_phone_in_talk CONSTANT)
    Q_PROPERTY(QString mdi_phone_incoming MEMBER mdi_phone_incoming CONSTANT)
    Q_PROPERTY(QString mdi_phone_lock MEMBER mdi_phone_lock CONSTANT)
    Q_PROPERTY(QString mdi_phone_log MEMBER mdi_phone_log CONSTANT)
    Q_PROPERTY(QString mdi_phone_minus MEMBER mdi_phone_minus CONSTANT)
    Q_PROPERTY(QString mdi_phone_missed MEMBER mdi_phone_missed CONSTANT)
    Q_PROPERTY(QString mdi_phone_off MEMBER mdi_phone_off CONSTANT)
    Q_PROPERTY(QString mdi_phone_outgoing MEMBER mdi_phone_outgoing CONSTANT)
    Q_PROPERTY(QString mdi_phone_outline MEMBER mdi_phone_outline CONSTANT)
    Q_PROPERTY(QString mdi_phone_paused MEMBER mdi_phone_paused CONSTANT)
    Q_PROPERTY(QString mdi_phone_plus MEMBER mdi_phone_plus CONSTANT)
    Q_PROPERTY(QString mdi_phone_return MEMBER mdi_phone_return CONSTANT)
    Q_PROPERTY(QString mdi_phone_rotate_landscape MEMBER mdi_phone_rotate_landscape CONSTANT)
    Q_PROPERTY(QString mdi_phone_rotate_portrait MEMBER mdi_phone_rotate_portrait CONSTANT)
    Q_PROPERTY(QString mdi_phone_settings MEMBER mdi_phone_settings CONSTANT)
    Q_PROPERTY(QString mdi_phone_voip MEMBER mdi_phone_voip CONSTANT)
    Q_PROPERTY(QString mdi_pi MEMBER mdi_pi CONSTANT)
    Q_PROPERTY(QString mdi_pi_box MEMBER mdi_pi_box CONSTANT)
    Q_PROPERTY(QString mdi_pi_hole MEMBER mdi_pi_hole CONSTANT)
    Q_PROPERTY(QString mdi_piano MEMBER mdi_piano CONSTANT)
    Q_PROPERTY(QString mdi_pickaxe MEMBER mdi_pickaxe CONSTANT)
    Q_PROPERTY(QString mdi_pier MEMBER mdi_pier CONSTANT)
    Q_PROPERTY(QString mdi_pier_crane MEMBER mdi_pier_crane CONSTANT)
    Q_PROPERTY(QString mdi_pig MEMBER mdi_pig CONSTANT)
    Q_PROPERTY(QString mdi_pill MEMBER mdi_pill CONSTANT)
    Q_PROPERTY(QString mdi_pillar MEMBER mdi_pillar CONSTANT)
    Q_PROPERTY(QString mdi_pin MEMBER mdi_pin CONSTANT)
    Q_PROPERTY(QString mdi_pin_off MEMBER mdi_pin_off CONSTANT)
    Q_PROPERTY(QString mdi_pin_off_outline MEMBER mdi_pin_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_pin_outline MEMBER mdi_pin_outline CONSTANT)
    Q_PROPERTY(QString mdi_pine_tree MEMBER mdi_pine_tree CONSTANT)
    Q_PROPERTY(QString mdi_pine_tree_box MEMBER mdi_pine_tree_box CONSTANT)
    Q_PROPERTY(QString mdi_pinterest MEMBER mdi_pinterest CONSTANT)
    Q_PROPERTY(QString mdi_pinterest_box MEMBER mdi_pinterest_box CONSTANT)
    Q_PROPERTY(QString mdi_pinwheel MEMBER mdi_pinwheel CONSTANT)
    Q_PROPERTY(QString mdi_pinwheel_outline MEMBER mdi_pinwheel_outline CONSTANT)
    Q_PROPERTY(QString mdi_pipe MEMBER mdi_pipe CONSTANT)
    Q_PROPERTY(QString mdi_pipe_disconnected MEMBER mdi_pipe_disconnected CONSTANT)
    Q_PROPERTY(QString mdi_pipe_leak MEMBER mdi_pipe_leak CONSTANT)
    Q_PROPERTY(QString mdi_pirate MEMBER mdi_pirate CONSTANT)
    Q_PROPERTY(QString mdi_pistol MEMBER mdi_pistol CONSTANT)
    Q_PROPERTY(QString mdi_piston MEMBER mdi_piston CONSTANT)
    Q_PROPERTY(QString mdi_pizza MEMBER mdi_pizza CONSTANT)
    Q_PROPERTY(QString mdi_play MEMBER mdi_play CONSTANT)
    Q_PROPERTY(QString mdi_play_box_outline MEMBER mdi_play_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_play_circle MEMBER mdi_play_circle CONSTANT)
    Q_PROPERTY(QString mdi_play_circle_outline MEMBER mdi_play_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_play_network MEMBER mdi_play_network CONSTANT)
    Q_PROPERTY(QString mdi_play_network_outline MEMBER mdi_play_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_play_pause MEMBER mdi_play_pause CONSTANT)
    Q_PROPERTY(QString mdi_play_protected_content MEMBER mdi_play_protected_content CONSTANT)
    Q_PROPERTY(QString mdi_play_speed MEMBER mdi_play_speed CONSTANT)
    Q_PROPERTY(QString mdi_playlist_check MEMBER mdi_playlist_check CONSTANT)
    Q_PROPERTY(QString mdi_playlist_edit MEMBER mdi_playlist_edit CONSTANT)
    Q_PROPERTY(QString mdi_playlist_minus MEMBER mdi_playlist_minus CONSTANT)
    Q_PROPERTY(QString mdi_playlist_music MEMBER mdi_playlist_music CONSTANT)
    Q_PROPERTY(QString mdi_playlist_music_outline MEMBER mdi_playlist_music_outline CONSTANT)
    Q_PROPERTY(QString mdi_playlist_play MEMBER mdi_playlist_play CONSTANT)
    Q_PROPERTY(QString mdi_playlist_plus MEMBER mdi_playlist_plus CONSTANT)
    Q_PROPERTY(QString mdi_playlist_remove MEMBER mdi_playlist_remove CONSTANT)
    Q_PROPERTY(QString mdi_playlist_star MEMBER mdi_playlist_star CONSTANT)
    Q_PROPERTY(QString mdi_playstation MEMBER mdi_playstation CONSTANT)
    Q_PROPERTY(QString mdi_plex MEMBER mdi_plex CONSTANT)
    Q_PROPERTY(QString mdi_plus MEMBER mdi_plus CONSTANT)
    Q_PROPERTY(QString mdi_plus_box MEMBER mdi_plus_box CONSTANT)
    Q_PROPERTY(QString mdi_plus_box_outline MEMBER mdi_plus_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_plus_circle MEMBER mdi_plus_circle CONSTANT)
    Q_PROPERTY(QString mdi_plus_circle_multiple_outline MEMBER mdi_plus_circle_multiple_outline CONSTANT)
    Q_PROPERTY(QString mdi_plus_circle_outline MEMBER mdi_plus_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_plus_minus MEMBER mdi_plus_minus CONSTANT)
    Q_PROPERTY(QString mdi_plus_minus_box MEMBER mdi_plus_minus_box CONSTANT)
    Q_PROPERTY(QString mdi_plus_network MEMBER mdi_plus_network CONSTANT)
    Q_PROPERTY(QString mdi_plus_network_outline MEMBER mdi_plus_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_plus_one MEMBER mdi_plus_one CONSTANT)
    Q_PROPERTY(QString mdi_plus_outline MEMBER mdi_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_pocket MEMBER mdi_pocket CONSTANT)
    Q_PROPERTY(QString mdi_podcast MEMBER mdi_podcast CONSTANT)
    Q_PROPERTY(QString mdi_podium MEMBER mdi_podium CONSTANT)
    Q_PROPERTY(QString mdi_podium_bronze MEMBER mdi_podium_bronze CONSTANT)
    Q_PROPERTY(QString mdi_podium_gold MEMBER mdi_podium_gold CONSTANT)
    Q_PROPERTY(QString mdi_podium_silver MEMBER mdi_podium_silver CONSTANT)
    Q_PROPERTY(QString mdi_point_of_sale MEMBER mdi_point_of_sale CONSTANT)
    Q_PROPERTY(QString mdi_pokeball MEMBER mdi_pokeball CONSTANT)
    Q_PROPERTY(QString mdi_pokemon_go MEMBER mdi_pokemon_go CONSTANT)
    Q_PROPERTY(QString mdi_poker_chip MEMBER mdi_poker_chip CONSTANT)
    Q_PROPERTY(QString mdi_polaroid MEMBER mdi_polaroid CONSTANT)
    Q_PROPERTY(QString mdi_poll MEMBER mdi_poll CONSTANT)
    Q_PROPERTY(QString mdi_poll_box MEMBER mdi_poll_box CONSTANT)
    Q_PROPERTY(QString mdi_polymer MEMBER mdi_polymer CONSTANT)
    Q_PROPERTY(QString mdi_pool MEMBER mdi_pool CONSTANT)
    Q_PROPERTY(QString mdi_popcorn MEMBER mdi_popcorn CONSTANT)
    Q_PROPERTY(QString mdi_postage_stamp MEMBER mdi_postage_stamp CONSTANT)
    Q_PROPERTY(QString mdi_pot MEMBER mdi_pot CONSTANT)
    Q_PROPERTY(QString mdi_pot_mix MEMBER mdi_pot_mix CONSTANT)
    Q_PROPERTY(QString mdi_pound MEMBER mdi_pound CONSTANT)
    Q_PROPERTY(QString mdi_pound_box MEMBER mdi_pound_box CONSTANT)
    Q_PROPERTY(QString mdi_power MEMBER mdi_power CONSTANT)
    Q_PROPERTY(QString mdi_power_cycle MEMBER mdi_power_cycle CONSTANT)
    Q_PROPERTY(QString mdi_power_off MEMBER mdi_power_off CONSTANT)
    Q_PROPERTY(QString mdi_power_on MEMBER mdi_power_on CONSTANT)
    Q_PROPERTY(QString mdi_power_plug MEMBER mdi_power_plug CONSTANT)
    Q_PROPERTY(QString mdi_power_plug_off MEMBER mdi_power_plug_off CONSTANT)
    Q_PROPERTY(QString mdi_power_settings MEMBER mdi_power_settings CONSTANT)
    Q_PROPERTY(QString mdi_power_sleep MEMBER mdi_power_sleep CONSTANT)
    Q_PROPERTY(QString mdi_power_socket MEMBER mdi_power_socket CONSTANT)
    Q_PROPERTY(QString mdi_power_socket_au MEMBER mdi_power_socket_au CONSTANT)
    Q_PROPERTY(QString mdi_power_socket_eu MEMBER mdi_power_socket_eu CONSTANT)
    Q_PROPERTY(QString mdi_power_socket_uk MEMBER mdi_power_socket_uk CONSTANT)
    Q_PROPERTY(QString mdi_power_socket_us MEMBER mdi_power_socket_us CONSTANT)
    Q_PROPERTY(QString mdi_power_standby MEMBER mdi_power_standby CONSTANT)
    Q_PROPERTY(QString mdi_powershell MEMBER mdi_powershell CONSTANT)
    Q_PROPERTY(QString mdi_prescription MEMBER mdi_prescription CONSTANT)
    Q_PROPERTY(QString mdi_presentation MEMBER mdi_presentation CONSTANT)
    Q_PROPERTY(QString mdi_presentation_play MEMBER mdi_presentation_play CONSTANT)
    Q_PROPERTY(QString mdi_printer MEMBER mdi_printer CONSTANT)
    Q_PROPERTY(QString mdi_printer_3d MEMBER mdi_printer_3d CONSTANT)
    Q_PROPERTY(QString mdi_printer_alert MEMBER mdi_printer_alert CONSTANT)
    Q_PROPERTY(QString mdi_printer_settings MEMBER mdi_printer_settings CONSTANT)
    Q_PROPERTY(QString mdi_printer_wireless MEMBER mdi_printer_wireless CONSTANT)
    Q_PROPERTY(QString mdi_priority_high MEMBER mdi_priority_high CONSTANT)
    Q_PROPERTY(QString mdi_priority_low MEMBER mdi_priority_low CONSTANT)
    Q_PROPERTY(QString mdi_professional_hexagon MEMBER mdi_professional_hexagon CONSTANT)
    Q_PROPERTY(QString mdi_progress_alert MEMBER mdi_progress_alert CONSTANT)
    Q_PROPERTY(QString mdi_progress_check MEMBER mdi_progress_check CONSTANT)
    Q_PROPERTY(QString mdi_progress_clock MEMBER mdi_progress_clock CONSTANT)
    Q_PROPERTY(QString mdi_progress_download MEMBER mdi_progress_download CONSTANT)
    Q_PROPERTY(QString mdi_progress_upload MEMBER mdi_progress_upload CONSTANT)
    Q_PROPERTY(QString mdi_progress_wrench MEMBER mdi_progress_wrench CONSTANT)
    Q_PROPERTY(QString mdi_projector MEMBER mdi_projector CONSTANT)
    Q_PROPERTY(QString mdi_projector_screen MEMBER mdi_projector_screen CONSTANT)
    Q_PROPERTY(QString mdi_publish MEMBER mdi_publish CONSTANT)
    Q_PROPERTY(QString mdi_pulse MEMBER mdi_pulse CONSTANT)
    Q_PROPERTY(QString mdi_pumpkin MEMBER mdi_pumpkin CONSTANT)
    Q_PROPERTY(QString mdi_puzzle MEMBER mdi_puzzle CONSTANT)
    Q_PROPERTY(QString mdi_puzzle_outline MEMBER mdi_puzzle_outline CONSTANT)
    Q_PROPERTY(QString mdi_qi MEMBER mdi_qi CONSTANT)
    Q_PROPERTY(QString mdi_qqchat MEMBER mdi_qqchat CONSTANT)
    Q_PROPERTY(QString mdi_qrcode MEMBER mdi_qrcode CONSTANT)
    Q_PROPERTY(QString mdi_qrcode_edit MEMBER mdi_qrcode_edit CONSTANT)
    Q_PROPERTY(QString mdi_qrcode_scan MEMBER mdi_qrcode_scan CONSTANT)
    Q_PROPERTY(QString mdi_quadcopter MEMBER mdi_quadcopter CONSTANT)
    Q_PROPERTY(QString mdi_quality_high MEMBER mdi_quality_high CONSTANT)
    Q_PROPERTY(QString mdi_quality_low MEMBER mdi_quality_low CONSTANT)
    Q_PROPERTY(QString mdi_quality_medium MEMBER mdi_quality_medium CONSTANT)
    Q_PROPERTY(QString mdi_quicktime MEMBER mdi_quicktime CONSTANT)
    Q_PROPERTY(QString mdi_quora MEMBER mdi_quora CONSTANT)
    Q_PROPERTY(QString mdi_rabbit MEMBER mdi_rabbit CONSTANT)
    Q_PROPERTY(QString mdi_racing_helmet MEMBER mdi_racing_helmet CONSTANT)
    Q_PROPERTY(QString mdi_racquetball MEMBER mdi_racquetball CONSTANT)
    Q_PROPERTY(QString mdi_radar MEMBER mdi_radar CONSTANT)
    Q_PROPERTY(QString mdi_radiator MEMBER mdi_radiator CONSTANT)
    Q_PROPERTY(QString mdi_radiator_disabled MEMBER mdi_radiator_disabled CONSTANT)
    Q_PROPERTY(QString mdi_radiator_off MEMBER mdi_radiator_off CONSTANT)
    Q_PROPERTY(QString mdi_radio MEMBER mdi_radio CONSTANT)
    Q_PROPERTY(QString mdi_radio_am MEMBER mdi_radio_am CONSTANT)
    Q_PROPERTY(QString mdi_radio_fm MEMBER mdi_radio_fm CONSTANT)
    Q_PROPERTY(QString mdi_radio_handheld MEMBER mdi_radio_handheld CONSTANT)
    Q_PROPERTY(QString mdi_radio_tower MEMBER mdi_radio_tower CONSTANT)
    Q_PROPERTY(QString mdi_radioactive MEMBER mdi_radioactive CONSTANT)
    Q_PROPERTY(QString mdi_radiobox_blank MEMBER mdi_radiobox_blank CONSTANT)
    Q_PROPERTY(QString mdi_radiobox_marked MEMBER mdi_radiobox_marked CONSTANT)
    Q_PROPERTY(QString mdi_radius MEMBER mdi_radius CONSTANT)
    Q_PROPERTY(QString mdi_radius_outline MEMBER mdi_radius_outline CONSTANT)
    Q_PROPERTY(QString mdi_raspberry_pi MEMBER mdi_raspberry_pi CONSTANT)
    Q_PROPERTY(QString mdi_ray_end MEMBER mdi_ray_end CONSTANT)
    Q_PROPERTY(QString mdi_ray_end_arrow MEMBER mdi_ray_end_arrow CONSTANT)
    Q_PROPERTY(QString mdi_ray_start MEMBER mdi_ray_start CONSTANT)
    Q_PROPERTY(QString mdi_ray_start_arrow MEMBER mdi_ray_start_arrow CONSTANT)
    Q_PROPERTY(QString mdi_ray_start_end MEMBER mdi_ray_start_end CONSTANT)
    Q_PROPERTY(QString mdi_ray_vertex MEMBER mdi_ray_vertex CONSTANT)
    Q_PROPERTY(QString mdi_react MEMBER mdi_react CONSTANT)
    Q_PROPERTY(QString mdi_read MEMBER mdi_read CONSTANT)
    Q_PROPERTY(QString mdi_receipt MEMBER mdi_receipt CONSTANT)
    Q_PROPERTY(QString mdi_record MEMBER mdi_record CONSTANT)
    Q_PROPERTY(QString mdi_record_player MEMBER mdi_record_player CONSTANT)
    Q_PROPERTY(QString mdi_record_rec MEMBER mdi_record_rec CONSTANT)
    Q_PROPERTY(QString mdi_recycle MEMBER mdi_recycle CONSTANT)
    Q_PROPERTY(QString mdi_reddit MEMBER mdi_reddit CONSTANT)
    Q_PROPERTY(QString mdi_redo MEMBER mdi_redo CONSTANT)
    Q_PROPERTY(QString mdi_redo_variant MEMBER mdi_redo_variant CONSTANT)
    Q_PROPERTY(QString mdi_reflect_horizontal MEMBER mdi_reflect_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_reflect_vertical MEMBER mdi_reflect_vertical CONSTANT)
    Q_PROPERTY(QString mdi_refresh MEMBER mdi_refresh CONSTANT)
    Q_PROPERTY(QString mdi_regex MEMBER mdi_regex CONSTANT)
    Q_PROPERTY(QString mdi_registered_trademark MEMBER mdi_registered_trademark CONSTANT)
    Q_PROPERTY(QString mdi_relative_scale MEMBER mdi_relative_scale CONSTANT)
    Q_PROPERTY(QString mdi_reload MEMBER mdi_reload CONSTANT)
    Q_PROPERTY(QString mdi_reminder MEMBER mdi_reminder CONSTANT)
    Q_PROPERTY(QString mdi_remote MEMBER mdi_remote CONSTANT)
    Q_PROPERTY(QString mdi_remote_desktop MEMBER mdi_remote_desktop CONSTANT)
    Q_PROPERTY(QString mdi_rename_box MEMBER mdi_rename_box CONSTANT)
    Q_PROPERTY(QString mdi_reorder_horizontal MEMBER mdi_reorder_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_reorder_vertical MEMBER mdi_reorder_vertical CONSTANT)
    Q_PROPERTY(QString mdi_repeat MEMBER mdi_repeat CONSTANT)
    Q_PROPERTY(QString mdi_repeat_off MEMBER mdi_repeat_off CONSTANT)
    Q_PROPERTY(QString mdi_repeat_once MEMBER mdi_repeat_once CONSTANT)
    Q_PROPERTY(QString mdi_replay MEMBER mdi_replay CONSTANT)
    Q_PROPERTY(QString mdi_reply MEMBER mdi_reply CONSTANT)
    Q_PROPERTY(QString mdi_reply_all MEMBER mdi_reply_all CONSTANT)
    Q_PROPERTY(QString mdi_reproduction MEMBER mdi_reproduction CONSTANT)
    Q_PROPERTY(QString mdi_resistor MEMBER mdi_resistor CONSTANT)
    Q_PROPERTY(QString mdi_resistor_nodes MEMBER mdi_resistor_nodes CONSTANT)
    Q_PROPERTY(QString mdi_resize MEMBER mdi_resize CONSTANT)
    Q_PROPERTY(QString mdi_resize_bottom_right MEMBER mdi_resize_bottom_right CONSTANT)
    Q_PROPERTY(QString mdi_responsive MEMBER mdi_responsive CONSTANT)
    Q_PROPERTY(QString mdi_restart MEMBER mdi_restart CONSTANT)
    Q_PROPERTY(QString mdi_restart_off MEMBER mdi_restart_off CONSTANT)
    Q_PROPERTY(QString mdi_restore MEMBER mdi_restore CONSTANT)
    Q_PROPERTY(QString mdi_restore_clock MEMBER mdi_restore_clock CONSTANT)
    Q_PROPERTY(QString mdi_rewind MEMBER mdi_rewind CONSTANT)
    Q_PROPERTY(QString mdi_rewind_10 MEMBER mdi_rewind_10 CONSTANT)
    Q_PROPERTY(QString mdi_rewind_30 MEMBER mdi_rewind_30 CONSTANT)
    Q_PROPERTY(QString mdi_rewind_outline MEMBER mdi_rewind_outline CONSTANT)
    Q_PROPERTY(QString mdi_rhombus MEMBER mdi_rhombus CONSTANT)
    Q_PROPERTY(QString mdi_rhombus_medium MEMBER mdi_rhombus_medium CONSTANT)
    Q_PROPERTY(QString mdi_rhombus_outline MEMBER mdi_rhombus_outline CONSTANT)
    Q_PROPERTY(QString mdi_rhombus_split MEMBER mdi_rhombus_split CONSTANT)
    Q_PROPERTY(QString mdi_ribbon MEMBER mdi_ribbon CONSTANT)
    Q_PROPERTY(QString mdi_rice MEMBER mdi_rice CONSTANT)
    Q_PROPERTY(QString mdi_ring MEMBER mdi_ring CONSTANT)
    Q_PROPERTY(QString mdi_road MEMBER mdi_road CONSTANT)
    Q_PROPERTY(QString mdi_road_variant MEMBER mdi_road_variant CONSTANT)
    Q_PROPERTY(QString mdi_robot MEMBER mdi_robot CONSTANT)
    Q_PROPERTY(QString mdi_robot_industrial MEMBER mdi_robot_industrial CONSTANT)
    Q_PROPERTY(QString mdi_robot_vacuum MEMBER mdi_robot_vacuum CONSTANT)
    Q_PROPERTY(QString mdi_robot_vacuum_variant MEMBER mdi_robot_vacuum_variant CONSTANT)
    Q_PROPERTY(QString mdi_rocket MEMBER mdi_rocket CONSTANT)
    Q_PROPERTY(QString mdi_roller_skate MEMBER mdi_roller_skate CONSTANT)
    Q_PROPERTY(QString mdi_rollerblade MEMBER mdi_rollerblade CONSTANT)
    Q_PROPERTY(QString mdi_rollupjs MEMBER mdi_rollupjs CONSTANT)
    Q_PROPERTY(QString mdi_room_service MEMBER mdi_room_service CONSTANT)
    Q_PROPERTY(QString mdi_room_service_outline MEMBER mdi_room_service_outline CONSTANT)
    Q_PROPERTY(QString mdi_rotate_3d MEMBER mdi_rotate_3d CONSTANT)
    Q_PROPERTY(QString mdi_rotate_left MEMBER mdi_rotate_left CONSTANT)
    Q_PROPERTY(QString mdi_rotate_left_variant MEMBER mdi_rotate_left_variant CONSTANT)
    Q_PROPERTY(QString mdi_rotate_orbit MEMBER mdi_rotate_orbit CONSTANT)
    Q_PROPERTY(QString mdi_rotate_right MEMBER mdi_rotate_right CONSTANT)
    Q_PROPERTY(QString mdi_rotate_right_variant MEMBER mdi_rotate_right_variant CONSTANT)
    Q_PROPERTY(QString mdi_rounded_corner MEMBER mdi_rounded_corner CONSTANT)
    Q_PROPERTY(QString mdi_router_wireless MEMBER mdi_router_wireless CONSTANT)
    Q_PROPERTY(QString mdi_router_wireless_settings MEMBER mdi_router_wireless_settings CONSTANT)
    Q_PROPERTY(QString mdi_routes MEMBER mdi_routes CONSTANT)
    Q_PROPERTY(QString mdi_rowing MEMBER mdi_rowing CONSTANT)
    Q_PROPERTY(QString mdi_rss MEMBER mdi_rss CONSTANT)
    Q_PROPERTY(QString mdi_rss_box MEMBER mdi_rss_box CONSTANT)
    Q_PROPERTY(QString mdi_ruby MEMBER mdi_ruby CONSTANT)
    Q_PROPERTY(QString mdi_rugby MEMBER mdi_rugby CONSTANT)
    Q_PROPERTY(QString mdi_ruler MEMBER mdi_ruler CONSTANT)
    Q_PROPERTY(QString mdi_ruler_square MEMBER mdi_ruler_square CONSTANT)
    Q_PROPERTY(QString mdi_run MEMBER mdi_run CONSTANT)
    Q_PROPERTY(QString mdi_run_fast MEMBER mdi_run_fast CONSTANT)
    Q_PROPERTY(QString mdi_sack MEMBER mdi_sack CONSTANT)
    Q_PROPERTY(QString mdi_sack_percent MEMBER mdi_sack_percent CONSTANT)
    Q_PROPERTY(QString mdi_safe MEMBER mdi_safe CONSTANT)
    Q_PROPERTY(QString mdi_safety_goggles MEMBER mdi_safety_goggles CONSTANT)
    Q_PROPERTY(QString mdi_sale MEMBER mdi_sale CONSTANT)
    Q_PROPERTY(QString mdi_salesforce MEMBER mdi_salesforce CONSTANT)
    Q_PROPERTY(QString mdi_sass MEMBER mdi_sass CONSTANT)
    Q_PROPERTY(QString mdi_satellite MEMBER mdi_satellite CONSTANT)
    Q_PROPERTY(QString mdi_satellite_uplink MEMBER mdi_satellite_uplink CONSTANT)
    Q_PROPERTY(QString mdi_satellite_variant MEMBER mdi_satellite_variant CONSTANT)
    Q_PROPERTY(QString mdi_sausage MEMBER mdi_sausage CONSTANT)
    Q_PROPERTY(QString mdi_saxophone MEMBER mdi_saxophone CONSTANT)
    Q_PROPERTY(QString mdi_scale MEMBER mdi_scale CONSTANT)
    Q_PROPERTY(QString mdi_scale_balance MEMBER mdi_scale_balance CONSTANT)
    Q_PROPERTY(QString mdi_scale_bathroom MEMBER mdi_scale_bathroom CONSTANT)
    Q_PROPERTY(QString mdi_scanner MEMBER mdi_scanner CONSTANT)
    Q_PROPERTY(QString mdi_scanner_off MEMBER mdi_scanner_off CONSTANT)
    Q_PROPERTY(QString mdi_school MEMBER mdi_school CONSTANT)
    Q_PROPERTY(QString mdi_scissors_cutting MEMBER mdi_scissors_cutting CONSTANT)
    Q_PROPERTY(QString mdi_screen_rotation MEMBER mdi_screen_rotation CONSTANT)
    Q_PROPERTY(QString mdi_screen_rotation_lock MEMBER mdi_screen_rotation_lock CONSTANT)
    Q_PROPERTY(QString mdi_screw_flat_top MEMBER mdi_screw_flat_top CONSTANT)
    Q_PROPERTY(QString mdi_screw_lag MEMBER mdi_screw_lag CONSTANT)
    Q_PROPERTY(QString mdi_screw_machine_flat_top MEMBER mdi_screw_machine_flat_top CONSTANT)
    Q_PROPERTY(QString mdi_screw_machine_round_top MEMBER mdi_screw_machine_round_top CONSTANT)
    Q_PROPERTY(QString mdi_screw_round_top MEMBER mdi_screw_round_top CONSTANT)
    Q_PROPERTY(QString mdi_screwdriver MEMBER mdi_screwdriver CONSTANT)
    Q_PROPERTY(QString mdi_script MEMBER mdi_script CONSTANT)
    Q_PROPERTY(QString mdi_script_outline MEMBER mdi_script_outline CONSTANT)
    Q_PROPERTY(QString mdi_script_text MEMBER mdi_script_text CONSTANT)
    Q_PROPERTY(QString mdi_script_text_outline MEMBER mdi_script_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_sd MEMBER mdi_sd CONSTANT)
    Q_PROPERTY(QString mdi_seal MEMBER mdi_seal CONSTANT)
    Q_PROPERTY(QString mdi_search_web MEMBER mdi_search_web CONSTANT)
    Q_PROPERTY(QString mdi_seat MEMBER mdi_seat CONSTANT)
    Q_PROPERTY(QString mdi_seat_flat MEMBER mdi_seat_flat CONSTANT)
    Q_PROPERTY(QString mdi_seat_flat_angled MEMBER mdi_seat_flat_angled CONSTANT)
    Q_PROPERTY(QString mdi_seat_individual_suite MEMBER mdi_seat_individual_suite CONSTANT)
    Q_PROPERTY(QString mdi_seat_legroom_extra MEMBER mdi_seat_legroom_extra CONSTANT)
    Q_PROPERTY(QString mdi_seat_legroom_normal MEMBER mdi_seat_legroom_normal CONSTANT)
    Q_PROPERTY(QString mdi_seat_legroom_reduced MEMBER mdi_seat_legroom_reduced CONSTANT)
    Q_PROPERTY(QString mdi_seat_outline MEMBER mdi_seat_outline CONSTANT)
    Q_PROPERTY(QString mdi_seat_recline_extra MEMBER mdi_seat_recline_extra CONSTANT)
    Q_PROPERTY(QString mdi_seat_recline_normal MEMBER mdi_seat_recline_normal CONSTANT)
    Q_PROPERTY(QString mdi_seatbelt MEMBER mdi_seatbelt CONSTANT)
    Q_PROPERTY(QString mdi_security MEMBER mdi_security CONSTANT)
    Q_PROPERTY(QString mdi_security_network MEMBER mdi_security_network CONSTANT)
    Q_PROPERTY(QString mdi_select MEMBER mdi_select CONSTANT)
    Q_PROPERTY(QString mdi_select_all MEMBER mdi_select_all CONSTANT)
    Q_PROPERTY(QString mdi_select_color MEMBER mdi_select_color CONSTANT)
    Q_PROPERTY(QString mdi_select_compare MEMBER mdi_select_compare CONSTANT)
    Q_PROPERTY(QString mdi_select_drag MEMBER mdi_select_drag CONSTANT)
    Q_PROPERTY(QString mdi_select_inverse MEMBER mdi_select_inverse CONSTANT)
    Q_PROPERTY(QString mdi_select_off MEMBER mdi_select_off CONSTANT)
    Q_PROPERTY(QString mdi_selection MEMBER mdi_selection CONSTANT)
    Q_PROPERTY(QString mdi_selection_drag MEMBER mdi_selection_drag CONSTANT)
    Q_PROPERTY(QString mdi_selection_ellipse MEMBER mdi_selection_ellipse CONSTANT)
    Q_PROPERTY(QString mdi_selection_off MEMBER mdi_selection_off CONSTANT)
    Q_PROPERTY(QString mdi_send MEMBER mdi_send CONSTANT)
    Q_PROPERTY(QString mdi_send_circle MEMBER mdi_send_circle CONSTANT)
    Q_PROPERTY(QString mdi_send_circle_outline MEMBER mdi_send_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_send_lock MEMBER mdi_send_lock CONSTANT)
    Q_PROPERTY(QString mdi_serial_port MEMBER mdi_serial_port CONSTANT)
    Q_PROPERTY(QString mdi_server MEMBER mdi_server CONSTANT)
    Q_PROPERTY(QString mdi_server_minus MEMBER mdi_server_minus CONSTANT)
    Q_PROPERTY(QString mdi_server_network MEMBER mdi_server_network CONSTANT)
    Q_PROPERTY(QString mdi_server_network_off MEMBER mdi_server_network_off CONSTANT)
    Q_PROPERTY(QString mdi_server_off MEMBER mdi_server_off CONSTANT)
    Q_PROPERTY(QString mdi_server_plus MEMBER mdi_server_plus CONSTANT)
    Q_PROPERTY(QString mdi_server_remove MEMBER mdi_server_remove CONSTANT)
    Q_PROPERTY(QString mdi_server_security MEMBER mdi_server_security CONSTANT)
    Q_PROPERTY(QString mdi_set_all MEMBER mdi_set_all CONSTANT)
    Q_PROPERTY(QString mdi_set_center MEMBER mdi_set_center CONSTANT)
    Q_PROPERTY(QString mdi_set_center_right MEMBER mdi_set_center_right CONSTANT)
    Q_PROPERTY(QString mdi_set_left MEMBER mdi_set_left CONSTANT)
    Q_PROPERTY(QString mdi_set_left_center MEMBER mdi_set_left_center CONSTANT)
    Q_PROPERTY(QString mdi_set_left_right MEMBER mdi_set_left_right CONSTANT)
    Q_PROPERTY(QString mdi_set_none MEMBER mdi_set_none CONSTANT)
    Q_PROPERTY(QString mdi_set_right MEMBER mdi_set_right CONSTANT)
    Q_PROPERTY(QString mdi_set_top_box MEMBER mdi_set_top_box CONSTANT)
    Q_PROPERTY(QString mdi_settings MEMBER mdi_settings CONSTANT)
    Q_PROPERTY(QString mdi_settings_box MEMBER mdi_settings_box CONSTANT)
    Q_PROPERTY(QString mdi_settings_helper MEMBER mdi_settings_helper CONSTANT)
    Q_PROPERTY(QString mdi_settings_outline MEMBER mdi_settings_outline CONSTANT)
    Q_PROPERTY(QString mdi_shape MEMBER mdi_shape CONSTANT)
    Q_PROPERTY(QString mdi_shape_circle_plus MEMBER mdi_shape_circle_plus CONSTANT)
    Q_PROPERTY(QString mdi_shape_outline MEMBER mdi_shape_outline CONSTANT)
    Q_PROPERTY(QString mdi_shape_plus MEMBER mdi_shape_plus CONSTANT)
    Q_PROPERTY(QString mdi_shape_polygon_plus MEMBER mdi_shape_polygon_plus CONSTANT)
    Q_PROPERTY(QString mdi_shape_rectangle_plus MEMBER mdi_shape_rectangle_plus CONSTANT)
    Q_PROPERTY(QString mdi_shape_square_plus MEMBER mdi_shape_square_plus CONSTANT)
    Q_PROPERTY(QString mdi_share MEMBER mdi_share CONSTANT)
    Q_PROPERTY(QString mdi_share_outline MEMBER mdi_share_outline CONSTANT)
    Q_PROPERTY(QString mdi_share_variant MEMBER mdi_share_variant CONSTANT)
    Q_PROPERTY(QString mdi_sheep MEMBER mdi_sheep CONSTANT)
    Q_PROPERTY(QString mdi_shield MEMBER mdi_shield CONSTANT)
    Q_PROPERTY(QString mdi_shield_account MEMBER mdi_shield_account CONSTANT)
    Q_PROPERTY(QString mdi_shield_account_outline MEMBER mdi_shield_account_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_airplane MEMBER mdi_shield_airplane CONSTANT)
    Q_PROPERTY(QString mdi_shield_airplane_outline MEMBER mdi_shield_airplane_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_check MEMBER mdi_shield_check CONSTANT)
    Q_PROPERTY(QString mdi_shield_check_outline MEMBER mdi_shield_check_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_cross MEMBER mdi_shield_cross CONSTANT)
    Q_PROPERTY(QString mdi_shield_cross_outline MEMBER mdi_shield_cross_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_half_full MEMBER mdi_shield_half_full CONSTANT)
    Q_PROPERTY(QString mdi_shield_home MEMBER mdi_shield_home CONSTANT)
    Q_PROPERTY(QString mdi_shield_home_outline MEMBER mdi_shield_home_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_key MEMBER mdi_shield_key CONSTANT)
    Q_PROPERTY(QString mdi_shield_key_outline MEMBER mdi_shield_key_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_link_variant MEMBER mdi_shield_link_variant CONSTANT)
    Q_PROPERTY(QString mdi_shield_link_variant_outline MEMBER mdi_shield_link_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_lock MEMBER mdi_shield_lock CONSTANT)
    Q_PROPERTY(QString mdi_shield_lock_outline MEMBER mdi_shield_lock_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_off MEMBER mdi_shield_off CONSTANT)
    Q_PROPERTY(QString mdi_shield_off_outline MEMBER mdi_shield_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_outline MEMBER mdi_shield_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_plus MEMBER mdi_shield_plus CONSTANT)
    Q_PROPERTY(QString mdi_shield_plus_outline MEMBER mdi_shield_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_remove MEMBER mdi_shield_remove CONSTANT)
    Q_PROPERTY(QString mdi_shield_remove_outline MEMBER mdi_shield_remove_outline CONSTANT)
    Q_PROPERTY(QString mdi_shield_search MEMBER mdi_shield_search CONSTANT)
    Q_PROPERTY(QString mdi_ship_wheel MEMBER mdi_ship_wheel CONSTANT)
    Q_PROPERTY(QString mdi_shoe_formal MEMBER mdi_shoe_formal CONSTANT)
    Q_PROPERTY(QString mdi_shoe_heel MEMBER mdi_shoe_heel CONSTANT)
    Q_PROPERTY(QString mdi_shoe_print MEMBER mdi_shoe_print CONSTANT)
    Q_PROPERTY(QString mdi_shopify MEMBER mdi_shopify CONSTANT)
    Q_PROPERTY(QString mdi_shopping MEMBER mdi_shopping CONSTANT)
    Q_PROPERTY(QString mdi_shopping_music MEMBER mdi_shopping_music CONSTANT)
    Q_PROPERTY(QString mdi_shovel MEMBER mdi_shovel CONSTANT)
    Q_PROPERTY(QString mdi_shovel_off MEMBER mdi_shovel_off CONSTANT)
    Q_PROPERTY(QString mdi_shower MEMBER mdi_shower CONSTANT)
    Q_PROPERTY(QString mdi_shower_head MEMBER mdi_shower_head CONSTANT)
    Q_PROPERTY(QString mdi_shredder MEMBER mdi_shredder CONSTANT)
    Q_PROPERTY(QString mdi_shuffle MEMBER mdi_shuffle CONSTANT)
    Q_PROPERTY(QString mdi_shuffle_disabled MEMBER mdi_shuffle_disabled CONSTANT)
    Q_PROPERTY(QString mdi_shuffle_variant MEMBER mdi_shuffle_variant CONSTANT)
    Q_PROPERTY(QString mdi_sigma MEMBER mdi_sigma CONSTANT)
    Q_PROPERTY(QString mdi_sigma_lower MEMBER mdi_sigma_lower CONSTANT)
    Q_PROPERTY(QString mdi_sign_caution MEMBER mdi_sign_caution CONSTANT)
    Q_PROPERTY(QString mdi_sign_direction MEMBER mdi_sign_direction CONSTANT)
    Q_PROPERTY(QString mdi_sign_text MEMBER mdi_sign_text CONSTANT)
    Q_PROPERTY(QString mdi_signal MEMBER mdi_signal CONSTANT)
    Q_PROPERTY(QString mdi_signal_2g MEMBER mdi_signal_2g CONSTANT)
    Q_PROPERTY(QString mdi_signal_3g MEMBER mdi_signal_3g CONSTANT)
    Q_PROPERTY(QString mdi_signal_4g MEMBER mdi_signal_4g CONSTANT)
    Q_PROPERTY(QString mdi_signal_5g MEMBER mdi_signal_5g CONSTANT)
    Q_PROPERTY(QString mdi_signal_cellular_1 MEMBER mdi_signal_cellular_1 CONSTANT)
    Q_PROPERTY(QString mdi_signal_cellular_2 MEMBER mdi_signal_cellular_2 CONSTANT)
    Q_PROPERTY(QString mdi_signal_cellular_3 MEMBER mdi_signal_cellular_3 CONSTANT)
    Q_PROPERTY(QString mdi_signal_cellular_outline MEMBER mdi_signal_cellular_outline CONSTANT)
    Q_PROPERTY(QString mdi_signal_hspa MEMBER mdi_signal_hspa CONSTANT)
    Q_PROPERTY(QString mdi_signal_hspa_plus MEMBER mdi_signal_hspa_plus CONSTANT)
    Q_PROPERTY(QString mdi_signal_off MEMBER mdi_signal_off CONSTANT)
    Q_PROPERTY(QString mdi_signal_variant MEMBER mdi_signal_variant CONSTANT)
    Q_PROPERTY(QString mdi_signature MEMBER mdi_signature CONSTANT)
    Q_PROPERTY(QString mdi_signature_freehand MEMBER mdi_signature_freehand CONSTANT)
    Q_PROPERTY(QString mdi_signature_image MEMBER mdi_signature_image CONSTANT)
    Q_PROPERTY(QString mdi_signature_text MEMBER mdi_signature_text CONSTANT)
    Q_PROPERTY(QString mdi_silo MEMBER mdi_silo CONSTANT)
    Q_PROPERTY(QString mdi_silverware MEMBER mdi_silverware CONSTANT)
    Q_PROPERTY(QString mdi_silverware_fork MEMBER mdi_silverware_fork CONSTANT)
    Q_PROPERTY(QString mdi_silverware_fork_knife MEMBER mdi_silverware_fork_knife CONSTANT)
    Q_PROPERTY(QString mdi_silverware_spoon MEMBER mdi_silverware_spoon CONSTANT)
    Q_PROPERTY(QString mdi_silverware_variant MEMBER mdi_silverware_variant CONSTANT)
    Q_PROPERTY(QString mdi_sim MEMBER mdi_sim CONSTANT)
    Q_PROPERTY(QString mdi_sim_alert MEMBER mdi_sim_alert CONSTANT)
    Q_PROPERTY(QString mdi_sim_off MEMBER mdi_sim_off CONSTANT)
    Q_PROPERTY(QString mdi_sina_weibo MEMBER mdi_sina_weibo CONSTANT)
    Q_PROPERTY(QString mdi_sitemap MEMBER mdi_sitemap CONSTANT)
    Q_PROPERTY(QString mdi_skate MEMBER mdi_skate CONSTANT)
    Q_PROPERTY(QString mdi_skew_less MEMBER mdi_skew_less CONSTANT)
    Q_PROPERTY(QString mdi_skew_more MEMBER mdi_skew_more CONSTANT)
    Q_PROPERTY(QString mdi_skip_backward MEMBER mdi_skip_backward CONSTANT)
    Q_PROPERTY(QString mdi_skip_forward MEMBER mdi_skip_forward CONSTANT)
    Q_PROPERTY(QString mdi_skip_next MEMBER mdi_skip_next CONSTANT)
    Q_PROPERTY(QString mdi_skip_next_circle MEMBER mdi_skip_next_circle CONSTANT)
    Q_PROPERTY(QString mdi_skip_next_circle_outline MEMBER mdi_skip_next_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_skip_previous MEMBER mdi_skip_previous CONSTANT)
    Q_PROPERTY(QString mdi_skip_previous_circle MEMBER mdi_skip_previous_circle CONSTANT)
    Q_PROPERTY(QString mdi_skip_previous_circle_outline MEMBER mdi_skip_previous_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_skull MEMBER mdi_skull CONSTANT)
    Q_PROPERTY(QString mdi_skull_crossbones MEMBER mdi_skull_crossbones CONSTANT)
    Q_PROPERTY(QString mdi_skull_crossbones_outline MEMBER mdi_skull_crossbones_outline CONSTANT)
    Q_PROPERTY(QString mdi_skull_outline MEMBER mdi_skull_outline CONSTANT)
    Q_PROPERTY(QString mdi_skype MEMBER mdi_skype CONSTANT)
    Q_PROPERTY(QString mdi_skype_business MEMBER mdi_skype_business CONSTANT)
    Q_PROPERTY(QString mdi_slack MEMBER mdi_slack CONSTANT)
    Q_PROPERTY(QString mdi_slackware MEMBER mdi_slackware CONSTANT)
    Q_PROPERTY(QString mdi_sleep MEMBER mdi_sleep CONSTANT)
    Q_PROPERTY(QString mdi_sleep_off MEMBER mdi_sleep_off CONSTANT)
    Q_PROPERTY(QString mdi_slope_downhill MEMBER mdi_slope_downhill CONSTANT)
    Q_PROPERTY(QString mdi_slope_uphill MEMBER mdi_slope_uphill CONSTANT)
    Q_PROPERTY(QString mdi_smog MEMBER mdi_smog CONSTANT)
    Q_PROPERTY(QString mdi_smoke_detector MEMBER mdi_smoke_detector CONSTANT)
    Q_PROPERTY(QString mdi_smoking MEMBER mdi_smoking CONSTANT)
    Q_PROPERTY(QString mdi_smoking_off MEMBER mdi_smoking_off CONSTANT)
    Q_PROPERTY(QString mdi_snapchat MEMBER mdi_snapchat CONSTANT)
    Q_PROPERTY(QString mdi_snowflake MEMBER mdi_snowflake CONSTANT)
    Q_PROPERTY(QString mdi_snowman MEMBER mdi_snowman CONSTANT)
    Q_PROPERTY(QString mdi_soccer MEMBER mdi_soccer CONSTANT)
    Q_PROPERTY(QString mdi_soccer_field MEMBER mdi_soccer_field CONSTANT)
    Q_PROPERTY(QString mdi_sofa MEMBER mdi_sofa CONSTANT)
    Q_PROPERTY(QString mdi_solar_panel MEMBER mdi_solar_panel CONSTANT)
    Q_PROPERTY(QString mdi_solar_panel_large MEMBER mdi_solar_panel_large CONSTANT)
    Q_PROPERTY(QString mdi_solar_power MEMBER mdi_solar_power CONSTANT)
    Q_PROPERTY(QString mdi_solid MEMBER mdi_solid CONSTANT)
    Q_PROPERTY(QString mdi_sort MEMBER mdi_sort CONSTANT)
    Q_PROPERTY(QString mdi_sort_alphabetical MEMBER mdi_sort_alphabetical CONSTANT)
    Q_PROPERTY(QString mdi_sort_ascending MEMBER mdi_sort_ascending CONSTANT)
    Q_PROPERTY(QString mdi_sort_descending MEMBER mdi_sort_descending CONSTANT)
    Q_PROPERTY(QString mdi_sort_numeric MEMBER mdi_sort_numeric CONSTANT)
    Q_PROPERTY(QString mdi_sort_variant MEMBER mdi_sort_variant CONSTANT)
    Q_PROPERTY(QString mdi_sort_variant_lock MEMBER mdi_sort_variant_lock CONSTANT)
    Q_PROPERTY(QString mdi_sort_variant_lock_open MEMBER mdi_sort_variant_lock_open CONSTANT)
    Q_PROPERTY(QString mdi_soundcloud MEMBER mdi_soundcloud CONSTANT)
    Q_PROPERTY(QString mdi_source_branch MEMBER mdi_source_branch CONSTANT)
    Q_PROPERTY(QString mdi_source_commit MEMBER mdi_source_commit CONSTANT)
    Q_PROPERTY(QString mdi_source_commit_end MEMBER mdi_source_commit_end CONSTANT)
    Q_PROPERTY(QString mdi_source_commit_end_local MEMBER mdi_source_commit_end_local CONSTANT)
    Q_PROPERTY(QString mdi_source_commit_local MEMBER mdi_source_commit_local CONSTANT)
    Q_PROPERTY(QString mdi_source_commit_next_local MEMBER mdi_source_commit_next_local CONSTANT)
    Q_PROPERTY(QString mdi_source_commit_start MEMBER mdi_source_commit_start CONSTANT)
    Q_PROPERTY(QString mdi_source_commit_start_next_local MEMBER mdi_source_commit_start_next_local CONSTANT)
    Q_PROPERTY(QString mdi_source_fork MEMBER mdi_source_fork CONSTANT)
    Q_PROPERTY(QString mdi_source_merge MEMBER mdi_source_merge CONSTANT)
    Q_PROPERTY(QString mdi_source_pull MEMBER mdi_source_pull CONSTANT)
    Q_PROPERTY(QString mdi_source_repository MEMBER mdi_source_repository CONSTANT)
    Q_PROPERTY(QString mdi_source_repository_multiple MEMBER mdi_source_repository_multiple CONSTANT)
    Q_PROPERTY(QString mdi_soy_sauce MEMBER mdi_soy_sauce CONSTANT)
    Q_PROPERTY(QString mdi_spa MEMBER mdi_spa CONSTANT)
    Q_PROPERTY(QString mdi_spa_outline MEMBER mdi_spa_outline CONSTANT)
    Q_PROPERTY(QString mdi_space_invaders MEMBER mdi_space_invaders CONSTANT)
    Q_PROPERTY(QString mdi_speaker MEMBER mdi_speaker CONSTANT)
    Q_PROPERTY(QString mdi_speaker_bluetooth MEMBER mdi_speaker_bluetooth CONSTANT)
    Q_PROPERTY(QString mdi_speaker_multiple MEMBER mdi_speaker_multiple CONSTANT)
    Q_PROPERTY(QString mdi_speaker_off MEMBER mdi_speaker_off CONSTANT)
    Q_PROPERTY(QString mdi_speaker_wireless MEMBER mdi_speaker_wireless CONSTANT)
    Q_PROPERTY(QString mdi_speedometer MEMBER mdi_speedometer CONSTANT)
    Q_PROPERTY(QString mdi_spellcheck MEMBER mdi_spellcheck CONSTANT)
    Q_PROPERTY(QString mdi_spider_web MEMBER mdi_spider_web CONSTANT)
    Q_PROPERTY(QString mdi_spotify MEMBER mdi_spotify CONSTANT)
    Q_PROPERTY(QString mdi_spotlight MEMBER mdi_spotlight CONSTANT)
    Q_PROPERTY(QString mdi_spotlight_beam MEMBER mdi_spotlight_beam CONSTANT)
    Q_PROPERTY(QString mdi_spray MEMBER mdi_spray CONSTANT)
    Q_PROPERTY(QString mdi_spray_bottle MEMBER mdi_spray_bottle CONSTANT)
    Q_PROPERTY(QString mdi_square MEMBER mdi_square CONSTANT)
    Q_PROPERTY(QString mdi_square_edit_outline MEMBER mdi_square_edit_outline CONSTANT)
    Q_PROPERTY(QString mdi_square_inc MEMBER mdi_square_inc CONSTANT)
    Q_PROPERTY(QString mdi_square_inc_cash MEMBER mdi_square_inc_cash CONSTANT)
    Q_PROPERTY(QString mdi_square_medium MEMBER mdi_square_medium CONSTANT)
    Q_PROPERTY(QString mdi_square_medium_outline MEMBER mdi_square_medium_outline CONSTANT)
    Q_PROPERTY(QString mdi_square_outline MEMBER mdi_square_outline CONSTANT)
    Q_PROPERTY(QString mdi_square_root MEMBER mdi_square_root CONSTANT)
    Q_PROPERTY(QString mdi_square_root_box MEMBER mdi_square_root_box CONSTANT)
    Q_PROPERTY(QString mdi_square_small MEMBER mdi_square_small CONSTANT)
    Q_PROPERTY(QString mdi_squeegee MEMBER mdi_squeegee CONSTANT)
    Q_PROPERTY(QString mdi_ssh MEMBER mdi_ssh CONSTANT)
    Q_PROPERTY(QString mdi_stack_exchange MEMBER mdi_stack_exchange CONSTANT)
    Q_PROPERTY(QString mdi_stack_overflow MEMBER mdi_stack_overflow CONSTANT)
    Q_PROPERTY(QString mdi_stadium MEMBER mdi_stadium CONSTANT)
    Q_PROPERTY(QString mdi_stairs MEMBER mdi_stairs CONSTANT)
    Q_PROPERTY(QString mdi_stamper MEMBER mdi_stamper CONSTANT)
    Q_PROPERTY(QString mdi_standard_definition MEMBER mdi_standard_definition CONSTANT)
    Q_PROPERTY(QString mdi_star MEMBER mdi_star CONSTANT)
    Q_PROPERTY(QString mdi_star_box MEMBER mdi_star_box CONSTANT)
    Q_PROPERTY(QString mdi_star_box_outline MEMBER mdi_star_box_outline CONSTANT)
    Q_PROPERTY(QString mdi_star_circle MEMBER mdi_star_circle CONSTANT)
    Q_PROPERTY(QString mdi_star_circle_outline MEMBER mdi_star_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_star_face MEMBER mdi_star_face CONSTANT)
    Q_PROPERTY(QString mdi_star_four_points MEMBER mdi_star_four_points CONSTANT)
    Q_PROPERTY(QString mdi_star_four_points_outline MEMBER mdi_star_four_points_outline CONSTANT)
    Q_PROPERTY(QString mdi_star_half MEMBER mdi_star_half CONSTANT)
    Q_PROPERTY(QString mdi_star_off MEMBER mdi_star_off CONSTANT)
    Q_PROPERTY(QString mdi_star_outline MEMBER mdi_star_outline CONSTANT)
    Q_PROPERTY(QString mdi_star_three_points MEMBER mdi_star_three_points CONSTANT)
    Q_PROPERTY(QString mdi_star_three_points_outline MEMBER mdi_star_three_points_outline CONSTANT)
    Q_PROPERTY(QString mdi_steam MEMBER mdi_steam CONSTANT)
    Q_PROPERTY(QString mdi_steam_box MEMBER mdi_steam_box CONSTANT)
    Q_PROPERTY(QString mdi_steering MEMBER mdi_steering CONSTANT)
    Q_PROPERTY(QString mdi_steering_off MEMBER mdi_steering_off CONSTANT)
    Q_PROPERTY(QString mdi_step_backward MEMBER mdi_step_backward CONSTANT)
    Q_PROPERTY(QString mdi_step_backward_2 MEMBER mdi_step_backward_2 CONSTANT)
    Q_PROPERTY(QString mdi_step_forward MEMBER mdi_step_forward CONSTANT)
    Q_PROPERTY(QString mdi_step_forward_2 MEMBER mdi_step_forward_2 CONSTANT)
    Q_PROPERTY(QString mdi_stethoscope MEMBER mdi_stethoscope CONSTANT)
    Q_PROPERTY(QString mdi_sticker MEMBER mdi_sticker CONSTANT)
    Q_PROPERTY(QString mdi_sticker_emoji MEMBER mdi_sticker_emoji CONSTANT)
    Q_PROPERTY(QString mdi_stocking MEMBER mdi_stocking CONSTANT)
    Q_PROPERTY(QString mdi_stop MEMBER mdi_stop CONSTANT)
    Q_PROPERTY(QString mdi_stop_circle MEMBER mdi_stop_circle CONSTANT)
    Q_PROPERTY(QString mdi_stop_circle_outline MEMBER mdi_stop_circle_outline CONSTANT)
    Q_PROPERTY(QString mdi_store MEMBER mdi_store CONSTANT)
    Q_PROPERTY(QString mdi_store_24_hour MEMBER mdi_store_24_hour CONSTANT)
    Q_PROPERTY(QString mdi_stove MEMBER mdi_stove CONSTANT)
    Q_PROPERTY(QString mdi_strava MEMBER mdi_strava CONSTANT)
    Q_PROPERTY(QString mdi_subdirectory_arrow_left MEMBER mdi_subdirectory_arrow_left CONSTANT)
    Q_PROPERTY(QString mdi_subdirectory_arrow_right MEMBER mdi_subdirectory_arrow_right CONSTANT)
    Q_PROPERTY(QString mdi_subtitles MEMBER mdi_subtitles CONSTANT)
    Q_PROPERTY(QString mdi_subtitles_outline MEMBER mdi_subtitles_outline CONSTANT)
    Q_PROPERTY(QString mdi_subway MEMBER mdi_subway CONSTANT)
    Q_PROPERTY(QString mdi_subway_alert_variant MEMBER mdi_subway_alert_variant CONSTANT)
    Q_PROPERTY(QString mdi_subway_variant MEMBER mdi_subway_variant CONSTANT)
    Q_PROPERTY(QString mdi_summit MEMBER mdi_summit CONSTANT)
    Q_PROPERTY(QString mdi_sunglasses MEMBER mdi_sunglasses CONSTANT)
    Q_PROPERTY(QString mdi_surround_sound MEMBER mdi_surround_sound CONSTANT)
    Q_PROPERTY(QString mdi_surround_sound_2_0 MEMBER mdi_surround_sound_2_0 CONSTANT)
    Q_PROPERTY(QString mdi_surround_sound_3_1 MEMBER mdi_surround_sound_3_1 CONSTANT)
    Q_PROPERTY(QString mdi_surround_sound_5_1 MEMBER mdi_surround_sound_5_1 CONSTANT)
    Q_PROPERTY(QString mdi_surround_sound_7_1 MEMBER mdi_surround_sound_7_1 CONSTANT)
    Q_PROPERTY(QString mdi_svg MEMBER mdi_svg CONSTANT)
    Q_PROPERTY(QString mdi_swap_horizontal MEMBER mdi_swap_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_swap_horizontal_bold MEMBER mdi_swap_horizontal_bold CONSTANT)
    Q_PROPERTY(QString mdi_swap_horizontal_variant MEMBER mdi_swap_horizontal_variant CONSTANT)
    Q_PROPERTY(QString mdi_swap_vertical MEMBER mdi_swap_vertical CONSTANT)
    Q_PROPERTY(QString mdi_swap_vertical_bold MEMBER mdi_swap_vertical_bold CONSTANT)
    Q_PROPERTY(QString mdi_swap_vertical_variant MEMBER mdi_swap_vertical_variant CONSTANT)
    Q_PROPERTY(QString mdi_swim MEMBER mdi_swim CONSTANT)
    Q_PROPERTY(QString mdi_switch MEMBER mdi_switch CONSTANT)
    Q_PROPERTY(QString mdi_sword MEMBER mdi_sword CONSTANT)
    Q_PROPERTY(QString mdi_sword_cross MEMBER mdi_sword_cross CONSTANT)
    Q_PROPERTY(QString mdi_symfony MEMBER mdi_symfony CONSTANT)
    Q_PROPERTY(QString mdi_sync MEMBER mdi_sync CONSTANT)
    Q_PROPERTY(QString mdi_sync_alert MEMBER mdi_sync_alert CONSTANT)
    Q_PROPERTY(QString mdi_sync_off MEMBER mdi_sync_off CONSTANT)
    Q_PROPERTY(QString mdi_tab MEMBER mdi_tab CONSTANT)
    Q_PROPERTY(QString mdi_tab_minus MEMBER mdi_tab_minus CONSTANT)
    Q_PROPERTY(QString mdi_tab_plus MEMBER mdi_tab_plus CONSTANT)
    Q_PROPERTY(QString mdi_tab_remove MEMBER mdi_tab_remove CONSTANT)
    Q_PROPERTY(QString mdi_tab_unselected MEMBER mdi_tab_unselected CONSTANT)
    Q_PROPERTY(QString mdi_table MEMBER mdi_table CONSTANT)
    Q_PROPERTY(QString mdi_table_border MEMBER mdi_table_border CONSTANT)
    Q_PROPERTY(QString mdi_table_column MEMBER mdi_table_column CONSTANT)
    Q_PROPERTY(QString mdi_table_column_plus_after MEMBER mdi_table_column_plus_after CONSTANT)
    Q_PROPERTY(QString mdi_table_column_plus_before MEMBER mdi_table_column_plus_before CONSTANT)
    Q_PROPERTY(QString mdi_table_column_remove MEMBER mdi_table_column_remove CONSTANT)
    Q_PROPERTY(QString mdi_table_column_width MEMBER mdi_table_column_width CONSTANT)
    Q_PROPERTY(QString mdi_table_edit MEMBER mdi_table_edit CONSTANT)
    Q_PROPERTY(QString mdi_table_large MEMBER mdi_table_large CONSTANT)
    Q_PROPERTY(QString mdi_table_merge_cells MEMBER mdi_table_merge_cells CONSTANT)
    Q_PROPERTY(QString mdi_table_of_contents MEMBER mdi_table_of_contents CONSTANT)
    Q_PROPERTY(QString mdi_table_plus MEMBER mdi_table_plus CONSTANT)
    Q_PROPERTY(QString mdi_table_remove MEMBER mdi_table_remove CONSTANT)
    Q_PROPERTY(QString mdi_table_row MEMBER mdi_table_row CONSTANT)
    Q_PROPERTY(QString mdi_table_row_height MEMBER mdi_table_row_height CONSTANT)
    Q_PROPERTY(QString mdi_table_row_plus_after MEMBER mdi_table_row_plus_after CONSTANT)
    Q_PROPERTY(QString mdi_table_row_plus_before MEMBER mdi_table_row_plus_before CONSTANT)
    Q_PROPERTY(QString mdi_table_row_remove MEMBER mdi_table_row_remove CONSTANT)
    Q_PROPERTY(QString mdi_table_search MEMBER mdi_table_search CONSTANT)
    Q_PROPERTY(QString mdi_table_settings MEMBER mdi_table_settings CONSTANT)
    Q_PROPERTY(QString mdi_tablet MEMBER mdi_tablet CONSTANT)
    Q_PROPERTY(QString mdi_tablet_android MEMBER mdi_tablet_android CONSTANT)
    Q_PROPERTY(QString mdi_tablet_cellphone MEMBER mdi_tablet_cellphone CONSTANT)
    Q_PROPERTY(QString mdi_tablet_ipad MEMBER mdi_tablet_ipad CONSTANT)
    Q_PROPERTY(QString mdi_taco MEMBER mdi_taco CONSTANT)
    Q_PROPERTY(QString mdi_tag MEMBER mdi_tag CONSTANT)
    Q_PROPERTY(QString mdi_tag_faces MEMBER mdi_tag_faces CONSTANT)
    Q_PROPERTY(QString mdi_tag_heart MEMBER mdi_tag_heart CONSTANT)
    Q_PROPERTY(QString mdi_tag_heart_outline MEMBER mdi_tag_heart_outline CONSTANT)
    Q_PROPERTY(QString mdi_tag_minus MEMBER mdi_tag_minus CONSTANT)
    Q_PROPERTY(QString mdi_tag_multiple MEMBER mdi_tag_multiple CONSTANT)
    Q_PROPERTY(QString mdi_tag_outline MEMBER mdi_tag_outline CONSTANT)
    Q_PROPERTY(QString mdi_tag_plus MEMBER mdi_tag_plus CONSTANT)
    Q_PROPERTY(QString mdi_tag_remove MEMBER mdi_tag_remove CONSTANT)
    Q_PROPERTY(QString mdi_tag_text_outline MEMBER mdi_tag_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_tank MEMBER mdi_tank CONSTANT)
    Q_PROPERTY(QString mdi_tape_measure MEMBER mdi_tape_measure CONSTANT)
    Q_PROPERTY(QString mdi_target MEMBER mdi_target CONSTANT)
    Q_PROPERTY(QString mdi_target_account MEMBER mdi_target_account CONSTANT)
    Q_PROPERTY(QString mdi_target_variant MEMBER mdi_target_variant CONSTANT)
    Q_PROPERTY(QString mdi_taxi MEMBER mdi_taxi CONSTANT)
    Q_PROPERTY(QString mdi_tea MEMBER mdi_tea CONSTANT)
    Q_PROPERTY(QString mdi_tea_outline MEMBER mdi_tea_outline CONSTANT)
    Q_PROPERTY(QString mdi_teach MEMBER mdi_teach CONSTANT)
    Q_PROPERTY(QString mdi_teamviewer MEMBER mdi_teamviewer CONSTANT)
    Q_PROPERTY(QString mdi_telegram MEMBER mdi_telegram CONSTANT)
    Q_PROPERTY(QString mdi_telescope MEMBER mdi_telescope CONSTANT)
    Q_PROPERTY(QString mdi_television MEMBER mdi_television CONSTANT)
    Q_PROPERTY(QString mdi_television_box MEMBER mdi_television_box CONSTANT)
    Q_PROPERTY(QString mdi_television_classic MEMBER mdi_television_classic CONSTANT)
    Q_PROPERTY(QString mdi_television_classic_off MEMBER mdi_television_classic_off CONSTANT)
    Q_PROPERTY(QString mdi_television_guide MEMBER mdi_television_guide CONSTANT)
    Q_PROPERTY(QString mdi_television_off MEMBER mdi_television_off CONSTANT)
    Q_PROPERTY(QString mdi_temperature_celsius MEMBER mdi_temperature_celsius CONSTANT)
    Q_PROPERTY(QString mdi_temperature_fahrenheit MEMBER mdi_temperature_fahrenheit CONSTANT)
    Q_PROPERTY(QString mdi_temperature_kelvin MEMBER mdi_temperature_kelvin CONSTANT)
    Q_PROPERTY(QString mdi_tennis MEMBER mdi_tennis CONSTANT)
    Q_PROPERTY(QString mdi_tennis_ball MEMBER mdi_tennis_ball CONSTANT)
    Q_PROPERTY(QString mdi_tent MEMBER mdi_tent CONSTANT)
    Q_PROPERTY(QString mdi_terrain MEMBER mdi_terrain CONSTANT)
    Q_PROPERTY(QString mdi_test_tube MEMBER mdi_test_tube CONSTANT)
    Q_PROPERTY(QString mdi_test_tube_empty MEMBER mdi_test_tube_empty CONSTANT)
    Q_PROPERTY(QString mdi_test_tube_off MEMBER mdi_test_tube_off CONSTANT)
    Q_PROPERTY(QString mdi_text MEMBER mdi_text CONSTANT)
    Q_PROPERTY(QString mdi_text_shadow MEMBER mdi_text_shadow CONSTANT)
    Q_PROPERTY(QString mdi_text_short MEMBER mdi_text_short CONSTANT)
    Q_PROPERTY(QString mdi_text_subject MEMBER mdi_text_subject CONSTANT)
    Q_PROPERTY(QString mdi_text_to_speech MEMBER mdi_text_to_speech CONSTANT)
    Q_PROPERTY(QString mdi_text_to_speech_off MEMBER mdi_text_to_speech_off CONSTANT)
    Q_PROPERTY(QString mdi_textbox MEMBER mdi_textbox CONSTANT)
    Q_PROPERTY(QString mdi_textbox_password MEMBER mdi_textbox_password CONSTANT)
    Q_PROPERTY(QString mdi_texture MEMBER mdi_texture CONSTANT)
    Q_PROPERTY(QString mdi_theater MEMBER mdi_theater CONSTANT)
    Q_PROPERTY(QString mdi_theme_light_dark MEMBER mdi_theme_light_dark CONSTANT)
    Q_PROPERTY(QString mdi_thermometer MEMBER mdi_thermometer CONSTANT)
    Q_PROPERTY(QString mdi_thermometer_alert MEMBER mdi_thermometer_alert CONSTANT)
    Q_PROPERTY(QString mdi_thermometer_chevron_down MEMBER mdi_thermometer_chevron_down CONSTANT)
    Q_PROPERTY(QString mdi_thermometer_chevron_up MEMBER mdi_thermometer_chevron_up CONSTANT)
    Q_PROPERTY(QString mdi_thermometer_lines MEMBER mdi_thermometer_lines CONSTANT)
    Q_PROPERTY(QString mdi_thermometer_minus MEMBER mdi_thermometer_minus CONSTANT)
    Q_PROPERTY(QString mdi_thermometer_plus MEMBER mdi_thermometer_plus CONSTANT)
    Q_PROPERTY(QString mdi_thermostat MEMBER mdi_thermostat CONSTANT)
    Q_PROPERTY(QString mdi_thermostat_box MEMBER mdi_thermostat_box CONSTANT)
    Q_PROPERTY(QString mdi_thought_bubble MEMBER mdi_thought_bubble CONSTANT)
    Q_PROPERTY(QString mdi_thought_bubble_outline MEMBER mdi_thought_bubble_outline CONSTANT)
    Q_PROPERTY(QString mdi_thumb_down MEMBER mdi_thumb_down CONSTANT)
    Q_PROPERTY(QString mdi_thumb_down_outline MEMBER mdi_thumb_down_outline CONSTANT)
    Q_PROPERTY(QString mdi_thumb_up MEMBER mdi_thumb_up CONSTANT)
    Q_PROPERTY(QString mdi_thumb_up_outline MEMBER mdi_thumb_up_outline CONSTANT)
    Q_PROPERTY(QString mdi_thumbs_up_down MEMBER mdi_thumbs_up_down CONSTANT)
    Q_PROPERTY(QString mdi_ticket MEMBER mdi_ticket CONSTANT)
    Q_PROPERTY(QString mdi_ticket_account MEMBER mdi_ticket_account CONSTANT)
    Q_PROPERTY(QString mdi_ticket_confirmation MEMBER mdi_ticket_confirmation CONSTANT)
    Q_PROPERTY(QString mdi_ticket_outline MEMBER mdi_ticket_outline CONSTANT)
    Q_PROPERTY(QString mdi_ticket_percent MEMBER mdi_ticket_percent CONSTANT)
    Q_PROPERTY(QString mdi_tie MEMBER mdi_tie CONSTANT)
    Q_PROPERTY(QString mdi_tilde MEMBER mdi_tilde CONSTANT)
    Q_PROPERTY(QString mdi_timelapse MEMBER mdi_timelapse CONSTANT)
    Q_PROPERTY(QString mdi_timeline MEMBER mdi_timeline CONSTANT)
    Q_PROPERTY(QString mdi_timeline_outline MEMBER mdi_timeline_outline CONSTANT)
    Q_PROPERTY(QString mdi_timeline_text MEMBER mdi_timeline_text CONSTANT)
    Q_PROPERTY(QString mdi_timeline_text_outline MEMBER mdi_timeline_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_timer MEMBER mdi_timer CONSTANT)
    Q_PROPERTY(QString mdi_timer_10 MEMBER mdi_timer_10 CONSTANT)
    Q_PROPERTY(QString mdi_timer_3 MEMBER mdi_timer_3 CONSTANT)
    Q_PROPERTY(QString mdi_timer_off MEMBER mdi_timer_off CONSTANT)
    Q_PROPERTY(QString mdi_timer_sand MEMBER mdi_timer_sand CONSTANT)
    Q_PROPERTY(QString mdi_timer_sand_empty MEMBER mdi_timer_sand_empty CONSTANT)
    Q_PROPERTY(QString mdi_timer_sand_full MEMBER mdi_timer_sand_full CONSTANT)
    Q_PROPERTY(QString mdi_timetable MEMBER mdi_timetable CONSTANT)
    Q_PROPERTY(QString mdi_toaster_oven MEMBER mdi_toaster_oven CONSTANT)
    Q_PROPERTY(QString mdi_toggle_switch MEMBER mdi_toggle_switch CONSTANT)
    Q_PROPERTY(QString mdi_toggle_switch_off MEMBER mdi_toggle_switch_off CONSTANT)
    Q_PROPERTY(QString mdi_toggle_switch_off_outline MEMBER mdi_toggle_switch_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_toggle_switch_outline MEMBER mdi_toggle_switch_outline CONSTANT)
    Q_PROPERTY(QString mdi_toilet MEMBER mdi_toilet CONSTANT)
    Q_PROPERTY(QString mdi_toolbox MEMBER mdi_toolbox CONSTANT)
    Q_PROPERTY(QString mdi_toolbox_outline MEMBER mdi_toolbox_outline CONSTANT)
    Q_PROPERTY(QString mdi_tooltip MEMBER mdi_tooltip CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_account MEMBER mdi_tooltip_account CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_edit MEMBER mdi_tooltip_edit CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_image MEMBER mdi_tooltip_image CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_image_outline MEMBER mdi_tooltip_image_outline CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_outline MEMBER mdi_tooltip_outline CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_plus MEMBER mdi_tooltip_plus CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_plus_outline MEMBER mdi_tooltip_plus_outline CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_text MEMBER mdi_tooltip_text CONSTANT)
    Q_PROPERTY(QString mdi_tooltip_text_outline MEMBER mdi_tooltip_text_outline CONSTANT)
    Q_PROPERTY(QString mdi_tooth MEMBER mdi_tooth CONSTANT)
    Q_PROPERTY(QString mdi_tooth_outline MEMBER mdi_tooth_outline CONSTANT)
    Q_PROPERTY(QString mdi_tor MEMBER mdi_tor CONSTANT)
    Q_PROPERTY(QString mdi_tortoise MEMBER mdi_tortoise CONSTANT)
    Q_PROPERTY(QString mdi_tournament MEMBER mdi_tournament CONSTANT)
    Q_PROPERTY(QString mdi_tower_beach MEMBER mdi_tower_beach CONSTANT)
    Q_PROPERTY(QString mdi_tower_fire MEMBER mdi_tower_fire CONSTANT)
    Q_PROPERTY(QString mdi_towing MEMBER mdi_towing CONSTANT)
    Q_PROPERTY(QString mdi_track_light MEMBER mdi_track_light CONSTANT)
    Q_PROPERTY(QString mdi_trackpad MEMBER mdi_trackpad CONSTANT)
    Q_PROPERTY(QString mdi_trackpad_lock MEMBER mdi_trackpad_lock CONSTANT)
    Q_PROPERTY(QString mdi_tractor MEMBER mdi_tractor CONSTANT)
    Q_PROPERTY(QString mdi_trademark MEMBER mdi_trademark CONSTANT)
    Q_PROPERTY(QString mdi_traffic_light MEMBER mdi_traffic_light CONSTANT)
    Q_PROPERTY(QString mdi_train MEMBER mdi_train CONSTANT)
    Q_PROPERTY(QString mdi_train_car MEMBER mdi_train_car CONSTANT)
    Q_PROPERTY(QString mdi_train_variant MEMBER mdi_train_variant CONSTANT)
    Q_PROPERTY(QString mdi_tram MEMBER mdi_tram CONSTANT)
    Q_PROPERTY(QString mdi_transcribe MEMBER mdi_transcribe CONSTANT)
    Q_PROPERTY(QString mdi_transcribe_close MEMBER mdi_transcribe_close CONSTANT)
    Q_PROPERTY(QString mdi_transfer_down MEMBER mdi_transfer_down CONSTANT)
    Q_PROPERTY(QString mdi_transfer_left MEMBER mdi_transfer_left CONSTANT)
    Q_PROPERTY(QString mdi_transfer_right MEMBER mdi_transfer_right CONSTANT)
    Q_PROPERTY(QString mdi_transfer_up MEMBER mdi_transfer_up CONSTANT)
    Q_PROPERTY(QString mdi_transit_connection MEMBER mdi_transit_connection CONSTANT)
    Q_PROPERTY(QString mdi_transit_connection_variant MEMBER mdi_transit_connection_variant CONSTANT)
    Q_PROPERTY(QString mdi_transit_transfer MEMBER mdi_transit_transfer CONSTANT)
    Q_PROPERTY(QString mdi_transition MEMBER mdi_transition CONSTANT)
    Q_PROPERTY(QString mdi_transition_masked MEMBER mdi_transition_masked CONSTANT)
    Q_PROPERTY(QString mdi_translate MEMBER mdi_translate CONSTANT)
    Q_PROPERTY(QString mdi_translate_off MEMBER mdi_translate_off CONSTANT)
    Q_PROPERTY(QString mdi_transmission_tower MEMBER mdi_transmission_tower CONSTANT)
    Q_PROPERTY(QString mdi_trash_can MEMBER mdi_trash_can CONSTANT)
    Q_PROPERTY(QString mdi_trash_can_outline MEMBER mdi_trash_can_outline CONSTANT)
    Q_PROPERTY(QString mdi_treasure_chest MEMBER mdi_treasure_chest CONSTANT)
    Q_PROPERTY(QString mdi_tree MEMBER mdi_tree CONSTANT)
    Q_PROPERTY(QString mdi_trello MEMBER mdi_trello CONSTANT)
    Q_PROPERTY(QString mdi_trending_down MEMBER mdi_trending_down CONSTANT)
    Q_PROPERTY(QString mdi_trending_neutral MEMBER mdi_trending_neutral CONSTANT)
    Q_PROPERTY(QString mdi_trending_up MEMBER mdi_trending_up CONSTANT)
    Q_PROPERTY(QString mdi_triangle MEMBER mdi_triangle CONSTANT)
    Q_PROPERTY(QString mdi_triangle_outline MEMBER mdi_triangle_outline CONSTANT)
    Q_PROPERTY(QString mdi_triforce MEMBER mdi_triforce CONSTANT)
    Q_PROPERTY(QString mdi_trophy MEMBER mdi_trophy CONSTANT)
    Q_PROPERTY(QString mdi_trophy_award MEMBER mdi_trophy_award CONSTANT)
    Q_PROPERTY(QString mdi_trophy_broken MEMBER mdi_trophy_broken CONSTANT)
    Q_PROPERTY(QString mdi_trophy_outline MEMBER mdi_trophy_outline CONSTANT)
    Q_PROPERTY(QString mdi_trophy_variant MEMBER mdi_trophy_variant CONSTANT)
    Q_PROPERTY(QString mdi_trophy_variant_outline MEMBER mdi_trophy_variant_outline CONSTANT)
    Q_PROPERTY(QString mdi_truck MEMBER mdi_truck CONSTANT)
    Q_PROPERTY(QString mdi_truck_check MEMBER mdi_truck_check CONSTANT)
    Q_PROPERTY(QString mdi_truck_delivery MEMBER mdi_truck_delivery CONSTANT)
    Q_PROPERTY(QString mdi_truck_fast MEMBER mdi_truck_fast CONSTANT)
    Q_PROPERTY(QString mdi_truck_trailer MEMBER mdi_truck_trailer CONSTANT)
    Q_PROPERTY(QString mdi_tshirt_crew MEMBER mdi_tshirt_crew CONSTANT)
    Q_PROPERTY(QString mdi_tshirt_crew_outline MEMBER mdi_tshirt_crew_outline CONSTANT)
    Q_PROPERTY(QString mdi_tshirt_v MEMBER mdi_tshirt_v CONSTANT)
    Q_PROPERTY(QString mdi_tshirt_v_outline MEMBER mdi_tshirt_v_outline CONSTANT)
    Q_PROPERTY(QString mdi_tumble_dryer MEMBER mdi_tumble_dryer CONSTANT)
    Q_PROPERTY(QString mdi_tumblr MEMBER mdi_tumblr CONSTANT)
    Q_PROPERTY(QString mdi_tumblr_box MEMBER mdi_tumblr_box CONSTANT)
    Q_PROPERTY(QString mdi_tumblr_reblog MEMBER mdi_tumblr_reblog CONSTANT)
    Q_PROPERTY(QString mdi_tune MEMBER mdi_tune CONSTANT)
    Q_PROPERTY(QString mdi_tune_vertical MEMBER mdi_tune_vertical CONSTANT)
    Q_PROPERTY(QString mdi_turnstile MEMBER mdi_turnstile CONSTANT)
    Q_PROPERTY(QString mdi_turnstile_outline MEMBER mdi_turnstile_outline CONSTANT)
    Q_PROPERTY(QString mdi_turtle MEMBER mdi_turtle CONSTANT)
    Q_PROPERTY(QString mdi_twitch MEMBER mdi_twitch CONSTANT)
    Q_PROPERTY(QString mdi_twitter MEMBER mdi_twitter CONSTANT)
    Q_PROPERTY(QString mdi_twitter_box MEMBER mdi_twitter_box CONSTANT)
    Q_PROPERTY(QString mdi_twitter_circle MEMBER mdi_twitter_circle CONSTANT)
    Q_PROPERTY(QString mdi_twitter_retweet MEMBER mdi_twitter_retweet CONSTANT)
    Q_PROPERTY(QString mdi_two_factor_authentication MEMBER mdi_two_factor_authentication CONSTANT)
    Q_PROPERTY(QString mdi_uber MEMBER mdi_uber CONSTANT)
    Q_PROPERTY(QString mdi_ubisoft MEMBER mdi_ubisoft CONSTANT)
    Q_PROPERTY(QString mdi_ubuntu MEMBER mdi_ubuntu CONSTANT)
    Q_PROPERTY(QString mdi_ultra_high_definition MEMBER mdi_ultra_high_definition CONSTANT)
    Q_PROPERTY(QString mdi_umbraco MEMBER mdi_umbraco CONSTANT)
    Q_PROPERTY(QString mdi_umbrella MEMBER mdi_umbrella CONSTANT)
    Q_PROPERTY(QString mdi_umbrella_closed MEMBER mdi_umbrella_closed CONSTANT)
    Q_PROPERTY(QString mdi_umbrella_outline MEMBER mdi_umbrella_outline CONSTANT)
    Q_PROPERTY(QString mdi_undo MEMBER mdi_undo CONSTANT)
    Q_PROPERTY(QString mdi_undo_variant MEMBER mdi_undo_variant CONSTANT)
    Q_PROPERTY(QString mdi_unfold_less_horizontal MEMBER mdi_unfold_less_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_unfold_less_vertical MEMBER mdi_unfold_less_vertical CONSTANT)
    Q_PROPERTY(QString mdi_unfold_more_horizontal MEMBER mdi_unfold_more_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_unfold_more_vertical MEMBER mdi_unfold_more_vertical CONSTANT)
    Q_PROPERTY(QString mdi_ungroup MEMBER mdi_ungroup CONSTANT)
    Q_PROPERTY(QString mdi_unity MEMBER mdi_unity CONSTANT)
    Q_PROPERTY(QString mdi_unreal MEMBER mdi_unreal CONSTANT)
    Q_PROPERTY(QString mdi_untappd MEMBER mdi_untappd CONSTANT)
    Q_PROPERTY(QString mdi_update MEMBER mdi_update CONSTANT)
    Q_PROPERTY(QString mdi_upload MEMBER mdi_upload CONSTANT)
    Q_PROPERTY(QString mdi_upload_multiple MEMBER mdi_upload_multiple CONSTANT)
    Q_PROPERTY(QString mdi_upload_network MEMBER mdi_upload_network CONSTANT)
    Q_PROPERTY(QString mdi_upload_network_outline MEMBER mdi_upload_network_outline CONSTANT)
    Q_PROPERTY(QString mdi_upload_outline MEMBER mdi_upload_outline CONSTANT)
    Q_PROPERTY(QString mdi_usb MEMBER mdi_usb CONSTANT)
    Q_PROPERTY(QString mdi_van_passenger MEMBER mdi_van_passenger CONSTANT)
    Q_PROPERTY(QString mdi_van_utility MEMBER mdi_van_utility CONSTANT)
    Q_PROPERTY(QString mdi_vanish MEMBER mdi_vanish CONSTANT)
    Q_PROPERTY(QString mdi_variable MEMBER mdi_variable CONSTANT)
    Q_PROPERTY(QString mdi_vector_arrange_above MEMBER mdi_vector_arrange_above CONSTANT)
    Q_PROPERTY(QString mdi_vector_arrange_below MEMBER mdi_vector_arrange_below CONSTANT)
    Q_PROPERTY(QString mdi_vector_bezier MEMBER mdi_vector_bezier CONSTANT)
    Q_PROPERTY(QString mdi_vector_circle MEMBER mdi_vector_circle CONSTANT)
    Q_PROPERTY(QString mdi_vector_circle_variant MEMBER mdi_vector_circle_variant CONSTANT)
    Q_PROPERTY(QString mdi_vector_combine MEMBER mdi_vector_combine CONSTANT)
    Q_PROPERTY(QString mdi_vector_curve MEMBER mdi_vector_curve CONSTANT)
    Q_PROPERTY(QString mdi_vector_difference MEMBER mdi_vector_difference CONSTANT)
    Q_PROPERTY(QString mdi_vector_difference_ab MEMBER mdi_vector_difference_ab CONSTANT)
    Q_PROPERTY(QString mdi_vector_difference_ba MEMBER mdi_vector_difference_ba CONSTANT)
    Q_PROPERTY(QString mdi_vector_ellipse MEMBER mdi_vector_ellipse CONSTANT)
    Q_PROPERTY(QString mdi_vector_intersection MEMBER mdi_vector_intersection CONSTANT)
    Q_PROPERTY(QString mdi_vector_line MEMBER mdi_vector_line CONSTANT)
    Q_PROPERTY(QString mdi_vector_point MEMBER mdi_vector_point CONSTANT)
    Q_PROPERTY(QString mdi_vector_polygon MEMBER mdi_vector_polygon CONSTANT)
    Q_PROPERTY(QString mdi_vector_polyline MEMBER mdi_vector_polyline CONSTANT)
    Q_PROPERTY(QString mdi_vector_radius MEMBER mdi_vector_radius CONSTANT)
    Q_PROPERTY(QString mdi_vector_rectangle MEMBER mdi_vector_rectangle CONSTANT)
    Q_PROPERTY(QString mdi_vector_selection MEMBER mdi_vector_selection CONSTANT)
    Q_PROPERTY(QString mdi_vector_square MEMBER mdi_vector_square CONSTANT)
    Q_PROPERTY(QString mdi_vector_triangle MEMBER mdi_vector_triangle CONSTANT)
    Q_PROPERTY(QString mdi_vector_union MEMBER mdi_vector_union CONSTANT)
    Q_PROPERTY(QString mdi_venmo MEMBER mdi_venmo CONSTANT)
    Q_PROPERTY(QString mdi_vhs MEMBER mdi_vhs CONSTANT)
    Q_PROPERTY(QString mdi_vibrate MEMBER mdi_vibrate CONSTANT)
    Q_PROPERTY(QString mdi_vibrate_off MEMBER mdi_vibrate_off CONSTANT)
    Q_PROPERTY(QString mdi_video MEMBER mdi_video CONSTANT)
    Q_PROPERTY(QString mdi_video_3d MEMBER mdi_video_3d CONSTANT)
    Q_PROPERTY(QString mdi_video_4k_box MEMBER mdi_video_4k_box CONSTANT)
    Q_PROPERTY(QString mdi_video_account MEMBER mdi_video_account CONSTANT)
    Q_PROPERTY(QString mdi_video_image MEMBER mdi_video_image CONSTANT)
    Q_PROPERTY(QString mdi_video_input_antenna MEMBER mdi_video_input_antenna CONSTANT)
    Q_PROPERTY(QString mdi_video_input_component MEMBER mdi_video_input_component CONSTANT)
    Q_PROPERTY(QString mdi_video_input_hdmi MEMBER mdi_video_input_hdmi CONSTANT)
    Q_PROPERTY(QString mdi_video_input_svideo MEMBER mdi_video_input_svideo CONSTANT)
    Q_PROPERTY(QString mdi_video_minus MEMBER mdi_video_minus CONSTANT)
    Q_PROPERTY(QString mdi_video_off MEMBER mdi_video_off CONSTANT)
    Q_PROPERTY(QString mdi_video_off_outline MEMBER mdi_video_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_video_outline MEMBER mdi_video_outline CONSTANT)
    Q_PROPERTY(QString mdi_video_plus MEMBER mdi_video_plus CONSTANT)
    Q_PROPERTY(QString mdi_video_stabilization MEMBER mdi_video_stabilization CONSTANT)
    Q_PROPERTY(QString mdi_video_switch MEMBER mdi_video_switch CONSTANT)
    Q_PROPERTY(QString mdi_video_vintage MEMBER mdi_video_vintage CONSTANT)
    Q_PROPERTY(QString mdi_view_agenda MEMBER mdi_view_agenda CONSTANT)
    Q_PROPERTY(QString mdi_view_array MEMBER mdi_view_array CONSTANT)
    Q_PROPERTY(QString mdi_view_carousel MEMBER mdi_view_carousel CONSTANT)
    Q_PROPERTY(QString mdi_view_column MEMBER mdi_view_column CONSTANT)
    Q_PROPERTY(QString mdi_view_dashboard MEMBER mdi_view_dashboard CONSTANT)
    Q_PROPERTY(QString mdi_view_dashboard_outline MEMBER mdi_view_dashboard_outline CONSTANT)
    Q_PROPERTY(QString mdi_view_dashboard_variant MEMBER mdi_view_dashboard_variant CONSTANT)
    Q_PROPERTY(QString mdi_view_day MEMBER mdi_view_day CONSTANT)
    Q_PROPERTY(QString mdi_view_grid MEMBER mdi_view_grid CONSTANT)
    Q_PROPERTY(QString mdi_view_headline MEMBER mdi_view_headline CONSTANT)
    Q_PROPERTY(QString mdi_view_list MEMBER mdi_view_list CONSTANT)
    Q_PROPERTY(QString mdi_view_module MEMBER mdi_view_module CONSTANT)
    Q_PROPERTY(QString mdi_view_parallel MEMBER mdi_view_parallel CONSTANT)
    Q_PROPERTY(QString mdi_view_quilt MEMBER mdi_view_quilt CONSTANT)
    Q_PROPERTY(QString mdi_view_sequential MEMBER mdi_view_sequential CONSTANT)
    Q_PROPERTY(QString mdi_view_split_horizontal MEMBER mdi_view_split_horizontal CONSTANT)
    Q_PROPERTY(QString mdi_view_split_vertical MEMBER mdi_view_split_vertical CONSTANT)
    Q_PROPERTY(QString mdi_view_stream MEMBER mdi_view_stream CONSTANT)
    Q_PROPERTY(QString mdi_view_week MEMBER mdi_view_week CONSTANT)
    Q_PROPERTY(QString mdi_vimeo MEMBER mdi_vimeo CONSTANT)
    Q_PROPERTY(QString mdi_violin MEMBER mdi_violin CONSTANT)
    Q_PROPERTY(QString mdi_virtual_reality MEMBER mdi_virtual_reality CONSTANT)
    Q_PROPERTY(QString mdi_visual_studio MEMBER mdi_visual_studio CONSTANT)
    Q_PROPERTY(QString mdi_visual_studio_code MEMBER mdi_visual_studio_code CONSTANT)
    Q_PROPERTY(QString mdi_vk MEMBER mdi_vk CONSTANT)
    Q_PROPERTY(QString mdi_vk_box MEMBER mdi_vk_box CONSTANT)
    Q_PROPERTY(QString mdi_vk_circle MEMBER mdi_vk_circle CONSTANT)
    Q_PROPERTY(QString mdi_vlc MEMBER mdi_vlc CONSTANT)
    Q_PROPERTY(QString mdi_voice MEMBER mdi_voice CONSTANT)
    Q_PROPERTY(QString mdi_voicemail MEMBER mdi_voicemail CONSTANT)
    Q_PROPERTY(QString mdi_volleyball MEMBER mdi_volleyball CONSTANT)
    Q_PROPERTY(QString mdi_volume_high MEMBER mdi_volume_high CONSTANT)
    Q_PROPERTY(QString mdi_volume_low MEMBER mdi_volume_low CONSTANT)
    Q_PROPERTY(QString mdi_volume_medium MEMBER mdi_volume_medium CONSTANT)
    Q_PROPERTY(QString mdi_volume_minus MEMBER mdi_volume_minus CONSTANT)
    Q_PROPERTY(QString mdi_volume_mute MEMBER mdi_volume_mute CONSTANT)
    Q_PROPERTY(QString mdi_volume_off MEMBER mdi_volume_off CONSTANT)
    Q_PROPERTY(QString mdi_volume_plus MEMBER mdi_volume_plus CONSTANT)
    Q_PROPERTY(QString mdi_volume_variant_off MEMBER mdi_volume_variant_off CONSTANT)
    Q_PROPERTY(QString mdi_vote MEMBER mdi_vote CONSTANT)
    Q_PROPERTY(QString mdi_vote_outline MEMBER mdi_vote_outline CONSTANT)
    Q_PROPERTY(QString mdi_vpn MEMBER mdi_vpn CONSTANT)
    Q_PROPERTY(QString mdi_vuejs MEMBER mdi_vuejs CONSTANT)
    Q_PROPERTY(QString mdi_walk MEMBER mdi_walk CONSTANT)
    Q_PROPERTY(QString mdi_wall MEMBER mdi_wall CONSTANT)
    Q_PROPERTY(QString mdi_wall_sconce MEMBER mdi_wall_sconce CONSTANT)
    Q_PROPERTY(QString mdi_wall_sconce_flat MEMBER mdi_wall_sconce_flat CONSTANT)
    Q_PROPERTY(QString mdi_wall_sconce_variant MEMBER mdi_wall_sconce_variant CONSTANT)
    Q_PROPERTY(QString mdi_wallet MEMBER mdi_wallet CONSTANT)
    Q_PROPERTY(QString mdi_wallet_giftcard MEMBER mdi_wallet_giftcard CONSTANT)
    Q_PROPERTY(QString mdi_wallet_membership MEMBER mdi_wallet_membership CONSTANT)
    Q_PROPERTY(QString mdi_wallet_outline MEMBER mdi_wallet_outline CONSTANT)
    Q_PROPERTY(QString mdi_wallet_travel MEMBER mdi_wallet_travel CONSTANT)
    Q_PROPERTY(QString mdi_wallpaper MEMBER mdi_wallpaper CONSTANT)
    Q_PROPERTY(QString mdi_wan MEMBER mdi_wan CONSTANT)
    Q_PROPERTY(QString mdi_washing_machine MEMBER mdi_washing_machine CONSTANT)
    Q_PROPERTY(QString mdi_watch MEMBER mdi_watch CONSTANT)
    Q_PROPERTY(QString mdi_watch_export MEMBER mdi_watch_export CONSTANT)
    Q_PROPERTY(QString mdi_watch_export_variant MEMBER mdi_watch_export_variant CONSTANT)
    Q_PROPERTY(QString mdi_watch_import MEMBER mdi_watch_import CONSTANT)
    Q_PROPERTY(QString mdi_watch_import_variant MEMBER mdi_watch_import_variant CONSTANT)
    Q_PROPERTY(QString mdi_watch_variant MEMBER mdi_watch_variant CONSTANT)
    Q_PROPERTY(QString mdi_watch_vibrate MEMBER mdi_watch_vibrate CONSTANT)
    Q_PROPERTY(QString mdi_watch_vibrate_off MEMBER mdi_watch_vibrate_off CONSTANT)
    Q_PROPERTY(QString mdi_water MEMBER mdi_water CONSTANT)
    Q_PROPERTY(QString mdi_water_off MEMBER mdi_water_off CONSTANT)
    Q_PROPERTY(QString mdi_water_outline MEMBER mdi_water_outline CONSTANT)
    Q_PROPERTY(QString mdi_water_percent MEMBER mdi_water_percent CONSTANT)
    Q_PROPERTY(QString mdi_water_pump MEMBER mdi_water_pump CONSTANT)
    Q_PROPERTY(QString mdi_watermark MEMBER mdi_watermark CONSTANT)
    Q_PROPERTY(QString mdi_waves MEMBER mdi_waves CONSTANT)
    Q_PROPERTY(QString mdi_waze MEMBER mdi_waze CONSTANT)
    Q_PROPERTY(QString mdi_weather_cloudy MEMBER mdi_weather_cloudy CONSTANT)
    Q_PROPERTY(QString mdi_weather_fog MEMBER mdi_weather_fog CONSTANT)
    Q_PROPERTY(QString mdi_weather_hail MEMBER mdi_weather_hail CONSTANT)
    Q_PROPERTY(QString mdi_weather_hurricane MEMBER mdi_weather_hurricane CONSTANT)
    Q_PROPERTY(QString mdi_weather_lightning MEMBER mdi_weather_lightning CONSTANT)
    Q_PROPERTY(QString mdi_weather_lightning_rainy MEMBER mdi_weather_lightning_rainy CONSTANT)
    Q_PROPERTY(QString mdi_weather_night MEMBER mdi_weather_night CONSTANT)
    Q_PROPERTY(QString mdi_weather_partlycloudy MEMBER mdi_weather_partlycloudy CONSTANT)
    Q_PROPERTY(QString mdi_weather_pouring MEMBER mdi_weather_pouring CONSTANT)
    Q_PROPERTY(QString mdi_weather_rainy MEMBER mdi_weather_rainy CONSTANT)
    Q_PROPERTY(QString mdi_weather_snowy MEMBER mdi_weather_snowy CONSTANT)
    Q_PROPERTY(QString mdi_weather_snowy_rainy MEMBER mdi_weather_snowy_rainy CONSTANT)
    Q_PROPERTY(QString mdi_weather_sunny MEMBER mdi_weather_sunny CONSTANT)
    Q_PROPERTY(QString mdi_weather_sunset MEMBER mdi_weather_sunset CONSTANT)
    Q_PROPERTY(QString mdi_weather_sunset_down MEMBER mdi_weather_sunset_down CONSTANT)
    Q_PROPERTY(QString mdi_weather_sunset_up MEMBER mdi_weather_sunset_up CONSTANT)
    Q_PROPERTY(QString mdi_weather_windy MEMBER mdi_weather_windy CONSTANT)
    Q_PROPERTY(QString mdi_weather_windy_variant MEMBER mdi_weather_windy_variant CONSTANT)
    Q_PROPERTY(QString mdi_web MEMBER mdi_web CONSTANT)
    Q_PROPERTY(QString mdi_webcam MEMBER mdi_webcam CONSTANT)
    Q_PROPERTY(QString mdi_webhook MEMBER mdi_webhook CONSTANT)
    Q_PROPERTY(QString mdi_webpack MEMBER mdi_webpack CONSTANT)
    Q_PROPERTY(QString mdi_wechat MEMBER mdi_wechat CONSTANT)
    Q_PROPERTY(QString mdi_weight MEMBER mdi_weight CONSTANT)
    Q_PROPERTY(QString mdi_weight_gram MEMBER mdi_weight_gram CONSTANT)
    Q_PROPERTY(QString mdi_weight_kilogram MEMBER mdi_weight_kilogram CONSTANT)
    Q_PROPERTY(QString mdi_weight_pound MEMBER mdi_weight_pound CONSTANT)
    Q_PROPERTY(QString mdi_whatsapp MEMBER mdi_whatsapp CONSTANT)
    Q_PROPERTY(QString mdi_wheelchair_accessibility MEMBER mdi_wheelchair_accessibility CONSTANT)
    Q_PROPERTY(QString mdi_whistle MEMBER mdi_whistle CONSTANT)
    Q_PROPERTY(QString mdi_white_balance_auto MEMBER mdi_white_balance_auto CONSTANT)
    Q_PROPERTY(QString mdi_white_balance_incandescent MEMBER mdi_white_balance_incandescent CONSTANT)
    Q_PROPERTY(QString mdi_white_balance_iridescent MEMBER mdi_white_balance_iridescent CONSTANT)
    Q_PROPERTY(QString mdi_white_balance_sunny MEMBER mdi_white_balance_sunny CONSTANT)
    Q_PROPERTY(QString mdi_widgets MEMBER mdi_widgets CONSTANT)
    Q_PROPERTY(QString mdi_wifi MEMBER mdi_wifi CONSTANT)
    Q_PROPERTY(QString mdi_wifi_off MEMBER mdi_wifi_off CONSTANT)
    Q_PROPERTY(QString mdi_wifi_star MEMBER mdi_wifi_star CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_1 MEMBER mdi_wifi_strength_1 CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_1_alert MEMBER mdi_wifi_strength_1_alert CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_1_lock MEMBER mdi_wifi_strength_1_lock CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_2 MEMBER mdi_wifi_strength_2 CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_2_alert MEMBER mdi_wifi_strength_2_alert CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_2_lock MEMBER mdi_wifi_strength_2_lock CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_3 MEMBER mdi_wifi_strength_3 CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_3_alert MEMBER mdi_wifi_strength_3_alert CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_3_lock MEMBER mdi_wifi_strength_3_lock CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_4 MEMBER mdi_wifi_strength_4 CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_4_alert MEMBER mdi_wifi_strength_4_alert CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_4_lock MEMBER mdi_wifi_strength_4_lock CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_alert_outline MEMBER mdi_wifi_strength_alert_outline CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_lock_outline MEMBER mdi_wifi_strength_lock_outline CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_off MEMBER mdi_wifi_strength_off CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_off_outline MEMBER mdi_wifi_strength_off_outline CONSTANT)
    Q_PROPERTY(QString mdi_wifi_strength_outline MEMBER mdi_wifi_strength_outline CONSTANT)
    Q_PROPERTY(QString mdi_wii MEMBER mdi_wii CONSTANT)
    Q_PROPERTY(QString mdi_wiiu MEMBER mdi_wiiu CONSTANT)
    Q_PROPERTY(QString mdi_wikipedia MEMBER mdi_wikipedia CONSTANT)
    Q_PROPERTY(QString mdi_wind_turbine MEMBER mdi_wind_turbine CONSTANT)
    Q_PROPERTY(QString mdi_window_close MEMBER mdi_window_close CONSTANT)
    Q_PROPERTY(QString mdi_window_closed MEMBER mdi_window_closed CONSTANT)
    Q_PROPERTY(QString mdi_window_maximize MEMBER mdi_window_maximize CONSTANT)
    Q_PROPERTY(QString mdi_window_minimize MEMBER mdi_window_minimize CONSTANT)
    Q_PROPERTY(QString mdi_window_open MEMBER mdi_window_open CONSTANT)
    Q_PROPERTY(QString mdi_window_restore MEMBER mdi_window_restore CONSTANT)
    Q_PROPERTY(QString mdi_windows MEMBER mdi_windows CONSTANT)
    Q_PROPERTY(QString mdi_windows_classic MEMBER mdi_windows_classic CONSTANT)
    Q_PROPERTY(QString mdi_wiper MEMBER mdi_wiper CONSTANT)
    Q_PROPERTY(QString mdi_wiper_wash MEMBER mdi_wiper_wash CONSTANT)
    Q_PROPERTY(QString mdi_wordpress MEMBER mdi_wordpress CONSTANT)
    Q_PROPERTY(QString mdi_worker MEMBER mdi_worker CONSTANT)
    Q_PROPERTY(QString mdi_wrap MEMBER mdi_wrap CONSTANT)
    Q_PROPERTY(QString mdi_wrap_disabled MEMBER mdi_wrap_disabled CONSTANT)
    Q_PROPERTY(QString mdi_wrench MEMBER mdi_wrench CONSTANT)
    Q_PROPERTY(QString mdi_wrench_outline MEMBER mdi_wrench_outline CONSTANT)
    Q_PROPERTY(QString mdi_wunderlist MEMBER mdi_wunderlist CONSTANT)
    Q_PROPERTY(QString mdi_xamarin MEMBER mdi_xamarin CONSTANT)
    Q_PROPERTY(QString mdi_xamarin_outline MEMBER mdi_xamarin_outline CONSTANT)
    Q_PROPERTY(QString mdi_xaml MEMBER mdi_xaml CONSTANT)
    Q_PROPERTY(QString mdi_xbox MEMBER mdi_xbox CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller MEMBER mdi_xbox_controller CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_battery_alert MEMBER mdi_xbox_controller_battery_alert CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_battery_charging MEMBER mdi_xbox_controller_battery_charging CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_battery_empty MEMBER mdi_xbox_controller_battery_empty CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_battery_full MEMBER mdi_xbox_controller_battery_full CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_battery_low MEMBER mdi_xbox_controller_battery_low CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_battery_medium MEMBER mdi_xbox_controller_battery_medium CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_battery_unknown MEMBER mdi_xbox_controller_battery_unknown CONSTANT)
    Q_PROPERTY(QString mdi_xbox_controller_off MEMBER mdi_xbox_controller_off CONSTANT)
    Q_PROPERTY(QString mdi_xda MEMBER mdi_xda CONSTANT)
    Q_PROPERTY(QString mdi_xing MEMBER mdi_xing CONSTANT)
    Q_PROPERTY(QString mdi_xing_box MEMBER mdi_xing_box CONSTANT)
    Q_PROPERTY(QString mdi_xing_circle MEMBER mdi_xing_circle CONSTANT)
    Q_PROPERTY(QString mdi_xml MEMBER mdi_xml CONSTANT)
    Q_PROPERTY(QString mdi_xmpp MEMBER mdi_xmpp CONSTANT)
    Q_PROPERTY(QString mdi_yahoo MEMBER mdi_yahoo CONSTANT)
    Q_PROPERTY(QString mdi_yammer MEMBER mdi_yammer CONSTANT)
    Q_PROPERTY(QString mdi_yeast MEMBER mdi_yeast CONSTANT)
    Q_PROPERTY(QString mdi_yelp MEMBER mdi_yelp CONSTANT)
    Q_PROPERTY(QString mdi_yin_yang MEMBER mdi_yin_yang CONSTANT)
    Q_PROPERTY(QString mdi_youtube MEMBER mdi_youtube CONSTANT)
    Q_PROPERTY(QString mdi_youtube_creator_studio MEMBER mdi_youtube_creator_studio CONSTANT)
    Q_PROPERTY(QString mdi_youtube_gaming MEMBER mdi_youtube_gaming CONSTANT)
    Q_PROPERTY(QString mdi_youtube_subscription MEMBER mdi_youtube_subscription CONSTANT)
    Q_PROPERTY(QString mdi_youtube_tv MEMBER mdi_youtube_tv CONSTANT)
    Q_PROPERTY(QString mdi_z_wave MEMBER mdi_z_wave CONSTANT)
    Q_PROPERTY(QString mdi_zend MEMBER mdi_zend CONSTANT)
    Q_PROPERTY(QString mdi_zigbee MEMBER mdi_zigbee CONSTANT)
    Q_PROPERTY(QString mdi_zip_box MEMBER mdi_zip_box CONSTANT)
    Q_PROPERTY(QString mdi_zip_disk MEMBER mdi_zip_disk CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_aquarius MEMBER mdi_zodiac_aquarius CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_aries MEMBER mdi_zodiac_aries CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_cancer MEMBER mdi_zodiac_cancer CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_capricorn MEMBER mdi_zodiac_capricorn CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_gemini MEMBER mdi_zodiac_gemini CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_leo MEMBER mdi_zodiac_leo CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_libra MEMBER mdi_zodiac_libra CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_pisces MEMBER mdi_zodiac_pisces CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_sagittarius MEMBER mdi_zodiac_sagittarius CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_scorpio MEMBER mdi_zodiac_scorpio CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_taurus MEMBER mdi_zodiac_taurus CONSTANT)
    Q_PROPERTY(QString mdi_zodiac_virgo MEMBER mdi_zodiac_virgo CONSTANT)
    Q_PROPERTY(QString mdi_blank MEMBER mdi_blank CONSTANT)

public:
    MaterialIcons(QObject *parent = Q_NULLPTR);
    virtual ~MaterialIcons();

    static const QString mdi_family;

    static const QString mdi_access_point;
    static const QString mdi_access_point_network;
    static const QString mdi_access_point_network_off;
    static const QString mdi_account;
    static const QString mdi_account_alert;
    static const QString mdi_account_alert_outline;
    static const QString mdi_account_arrow_left;
    static const QString mdi_account_arrow_left_outline;
    static const QString mdi_account_arrow_right;
    static const QString mdi_account_arrow_right_outline;
    static const QString mdi_account_badge;
    static const QString mdi_account_badge_alert;
    static const QString mdi_account_badge_alert_outline;
    static const QString mdi_account_badge_outline;
    static const QString mdi_account_box;
    static const QString mdi_account_box_multiple;
    static const QString mdi_account_box_outline;
    static const QString mdi_account_card_details;
    static const QString mdi_account_card_details_outline;
    static const QString mdi_account_check;
    static const QString mdi_account_check_outline;
    static const QString mdi_account_child;
    static const QString mdi_account_child_circle;
    static const QString mdi_account_circle;
    static const QString mdi_account_circle_outline;
    static const QString mdi_account_clock;
    static const QString mdi_account_clock_outline;
    static const QString mdi_account_convert;
    static const QString mdi_account_details;
    static const QString mdi_account_edit;
    static const QString mdi_account_group;
    static const QString mdi_account_group_outline;
    static const QString mdi_account_heart;
    static const QString mdi_account_heart_outline;
    static const QString mdi_account_key;
    static const QString mdi_account_key_outline;
    static const QString mdi_account_minus;
    static const QString mdi_account_minus_outline;
    static const QString mdi_account_multiple;
    static const QString mdi_account_multiple_check;
    static const QString mdi_account_multiple_minus;
    static const QString mdi_account_multiple_minus_outline;
    static const QString mdi_account_multiple_outline;
    static const QString mdi_account_multiple_plus;
    static const QString mdi_account_multiple_plus_outline;
    static const QString mdi_account_network;
    static const QString mdi_account_network_outline;
    static const QString mdi_account_off;
    static const QString mdi_account_off_outline;
    static const QString mdi_account_outline;
    static const QString mdi_account_plus;
    static const QString mdi_account_plus_outline;
    static const QString mdi_account_question;
    static const QString mdi_account_question_outline;
    static const QString mdi_account_remove;
    static const QString mdi_account_remove_outline;
    static const QString mdi_account_search;
    static const QString mdi_account_search_outline;
    static const QString mdi_account_settings;
    static const QString mdi_account_star;
    static const QString mdi_account_star_outline;
    static const QString mdi_account_supervisor;
    static const QString mdi_account_supervisor_circle;
    static const QString mdi_account_switch;
    static const QString mdi_account_tie;
    static const QString mdi_accusoft;
    static const QString mdi_adchoices;
    static const QString mdi_adjust;
    static const QString mdi_adobe;
    static const QString mdi_air_conditioner;
    static const QString mdi_air_filter;
    static const QString mdi_air_horn;
    static const QString mdi_air_purifier;
    static const QString mdi_airbag;
    static const QString mdi_airballoon;
    static const QString mdi_airplane;
    static const QString mdi_airplane_landing;
    static const QString mdi_airplane_off;
    static const QString mdi_airplane_takeoff;
    static const QString mdi_airplay;
    static const QString mdi_airport;
    static const QString mdi_alarm;
    static const QString mdi_alarm_bell;
    static const QString mdi_alarm_check;
    static const QString mdi_alarm_light;
    static const QString mdi_alarm_light_outline;
    static const QString mdi_alarm_multiple;
    static const QString mdi_alarm_off;
    static const QString mdi_alarm_plus;
    static const QString mdi_alarm_snooze;
    static const QString mdi_album;
    static const QString mdi_alert;
    static const QString mdi_alert_box;
    static const QString mdi_alert_box_outline;
    static const QString mdi_alert_circle;
    static const QString mdi_alert_circle_outline;
    static const QString mdi_alert_decagram;
    static const QString mdi_alert_decagram_outline;
    static const QString mdi_alert_octagon;
    static const QString mdi_alert_octagon_outline;
    static const QString mdi_alert_octagram;
    static const QString mdi_alert_octagram_outline;
    static const QString mdi_alert_outline;
    static const QString mdi_alien;
    static const QString mdi_all_inclusive;
    static const QString mdi_alpha;
    static const QString mdi_alpha_a;
    static const QString mdi_alpha_a_box;
    static const QString mdi_alpha_a_box_outline;
    static const QString mdi_alpha_a_circle;
    static const QString mdi_alpha_a_circle_outline;
    static const QString mdi_alpha_b;
    static const QString mdi_alpha_b_box;
    static const QString mdi_alpha_b_box_outline;
    static const QString mdi_alpha_b_circle;
    static const QString mdi_alpha_b_circle_outline;
    static const QString mdi_alpha_c;
    static const QString mdi_alpha_c_box;
    static const QString mdi_alpha_c_box_outline;
    static const QString mdi_alpha_c_circle;
    static const QString mdi_alpha_c_circle_outline;
    static const QString mdi_alpha_d;
    static const QString mdi_alpha_d_box;
    static const QString mdi_alpha_d_box_outline;
    static const QString mdi_alpha_d_circle;
    static const QString mdi_alpha_d_circle_outline;
    static const QString mdi_alpha_e;
    static const QString mdi_alpha_e_box;
    static const QString mdi_alpha_e_box_outline;
    static const QString mdi_alpha_e_circle;
    static const QString mdi_alpha_e_circle_outline;
    static const QString mdi_alpha_f;
    static const QString mdi_alpha_f_box;
    static const QString mdi_alpha_f_box_outline;
    static const QString mdi_alpha_f_circle;
    static const QString mdi_alpha_f_circle_outline;
    static const QString mdi_alpha_g;
    static const QString mdi_alpha_g_box;
    static const QString mdi_alpha_g_box_outline;
    static const QString mdi_alpha_g_circle;
    static const QString mdi_alpha_g_circle_outline;
    static const QString mdi_alpha_h;
    static const QString mdi_alpha_h_box;
    static const QString mdi_alpha_h_box_outline;
    static const QString mdi_alpha_h_circle;
    static const QString mdi_alpha_h_circle_outline;
    static const QString mdi_alpha_i;
    static const QString mdi_alpha_i_box;
    static const QString mdi_alpha_i_box_outline;
    static const QString mdi_alpha_i_circle;
    static const QString mdi_alpha_i_circle_outline;
    static const QString mdi_alpha_j;
    static const QString mdi_alpha_j_box;
    static const QString mdi_alpha_j_box_outline;
    static const QString mdi_alpha_j_circle;
    static const QString mdi_alpha_j_circle_outline;
    static const QString mdi_alpha_k;
    static const QString mdi_alpha_k_box;
    static const QString mdi_alpha_k_box_outline;
    static const QString mdi_alpha_k_circle;
    static const QString mdi_alpha_k_circle_outline;
    static const QString mdi_alpha_l;
    static const QString mdi_alpha_l_box;
    static const QString mdi_alpha_l_box_outline;
    static const QString mdi_alpha_l_circle;
    static const QString mdi_alpha_l_circle_outline;
    static const QString mdi_alpha_m;
    static const QString mdi_alpha_m_box;
    static const QString mdi_alpha_m_box_outline;
    static const QString mdi_alpha_m_circle;
    static const QString mdi_alpha_m_circle_outline;
    static const QString mdi_alpha_n;
    static const QString mdi_alpha_n_box;
    static const QString mdi_alpha_n_box_outline;
    static const QString mdi_alpha_n_circle;
    static const QString mdi_alpha_n_circle_outline;
    static const QString mdi_alpha_o;
    static const QString mdi_alpha_o_box;
    static const QString mdi_alpha_o_box_outline;
    static const QString mdi_alpha_o_circle;
    static const QString mdi_alpha_o_circle_outline;
    static const QString mdi_alpha_p;
    static const QString mdi_alpha_p_box;
    static const QString mdi_alpha_p_box_outline;
    static const QString mdi_alpha_p_circle;
    static const QString mdi_alpha_p_circle_outline;
    static const QString mdi_alpha_q;
    static const QString mdi_alpha_q_box;
    static const QString mdi_alpha_q_box_outline;
    static const QString mdi_alpha_q_circle;
    static const QString mdi_alpha_q_circle_outline;
    static const QString mdi_alpha_r;
    static const QString mdi_alpha_r_box;
    static const QString mdi_alpha_r_box_outline;
    static const QString mdi_alpha_r_circle;
    static const QString mdi_alpha_r_circle_outline;
    static const QString mdi_alpha_s;
    static const QString mdi_alpha_s_box;
    static const QString mdi_alpha_s_box_outline;
    static const QString mdi_alpha_s_circle;
    static const QString mdi_alpha_s_circle_outline;
    static const QString mdi_alpha_t;
    static const QString mdi_alpha_t_box;
    static const QString mdi_alpha_t_box_outline;
    static const QString mdi_alpha_t_circle;
    static const QString mdi_alpha_t_circle_outline;
    static const QString mdi_alpha_u;
    static const QString mdi_alpha_u_box;
    static const QString mdi_alpha_u_box_outline;
    static const QString mdi_alpha_u_circle;
    static const QString mdi_alpha_u_circle_outline;
    static const QString mdi_alpha_v;
    static const QString mdi_alpha_v_box;
    static const QString mdi_alpha_v_box_outline;
    static const QString mdi_alpha_v_circle;
    static const QString mdi_alpha_v_circle_outline;
    static const QString mdi_alpha_w;
    static const QString mdi_alpha_w_box;
    static const QString mdi_alpha_w_box_outline;
    static const QString mdi_alpha_w_circle;
    static const QString mdi_alpha_w_circle_outline;
    static const QString mdi_alpha_x;
    static const QString mdi_alpha_x_box;
    static const QString mdi_alpha_x_box_outline;
    static const QString mdi_alpha_x_circle;
    static const QString mdi_alpha_x_circle_outline;
    static const QString mdi_alpha_y;
    static const QString mdi_alpha_y_box;
    static const QString mdi_alpha_y_box_outline;
    static const QString mdi_alpha_y_circle;
    static const QString mdi_alpha_y_circle_outline;
    static const QString mdi_alpha_z;
    static const QString mdi_alpha_z_box;
    static const QString mdi_alpha_z_box_outline;
    static const QString mdi_alpha_z_circle;
    static const QString mdi_alpha_z_circle_outline;
    static const QString mdi_alphabetical;
    static const QString mdi_altimeter;
    static const QString mdi_amazon;
    static const QString mdi_amazon_alexa;
    static const QString mdi_amazon_drive;
    static const QString mdi_ambulance;
    static const QString mdi_ammunition;
    static const QString mdi_ampersand;
    static const QString mdi_amplifier;
    static const QString mdi_anchor;
    static const QString mdi_android;
    static const QString mdi_android_auto;
    static const QString mdi_android_debug_bridge;
    static const QString mdi_android_head;
    static const QString mdi_android_messages;
    static const QString mdi_android_studio;
    static const QString mdi_angle_acute;
    static const QString mdi_angle_obtuse;
    static const QString mdi_angle_right;
    static const QString mdi_angular;
    static const QString mdi_angularjs;
    static const QString mdi_animation;
    static const QString mdi_animation_outline;
    static const QString mdi_animation_play;
    static const QString mdi_animation_play_outline;
    static const QString mdi_anvil;
    static const QString mdi_apple;
    static const QString mdi_apple_finder;
    static const QString mdi_apple_icloud;
    static const QString mdi_apple_ios;
    static const QString mdi_apple_keyboard_caps;
    static const QString mdi_apple_keyboard_command;
    static const QString mdi_apple_keyboard_control;
    static const QString mdi_apple_keyboard_option;
    static const QString mdi_apple_keyboard_shift;
    static const QString mdi_apple_safari;
    static const QString mdi_application;
    static const QString mdi_application_export;
    static const QString mdi_application_import;
    static const QString mdi_apps;
    static const QString mdi_apps_box;
    static const QString mdi_arch;
    static const QString mdi_archive;
    static const QString mdi_arrange_bring_forward;
    static const QString mdi_arrange_bring_to_front;
    static const QString mdi_arrange_send_backward;
    static const QString mdi_arrange_send_to_back;
    static const QString mdi_arrow_all;
    static const QString mdi_arrow_bottom_left;
    static const QString mdi_arrow_bottom_left_bold_outline;
    static const QString mdi_arrow_bottom_left_thick;
    static const QString mdi_arrow_bottom_right;
    static const QString mdi_arrow_bottom_right_bold_outline;
    static const QString mdi_arrow_bottom_right_thick;
    static const QString mdi_arrow_collapse;
    static const QString mdi_arrow_collapse_all;
    static const QString mdi_arrow_collapse_down;
    static const QString mdi_arrow_collapse_horizontal;
    static const QString mdi_arrow_collapse_left;
    static const QString mdi_arrow_collapse_right;
    static const QString mdi_arrow_collapse_up;
    static const QString mdi_arrow_collapse_vertical;
    static const QString mdi_arrow_decision;
    static const QString mdi_arrow_decision_auto;
    static const QString mdi_arrow_decision_auto_outline;
    static const QString mdi_arrow_decision_outline;
    static const QString mdi_arrow_down;
    static const QString mdi_arrow_down_bold;
    static const QString mdi_arrow_down_bold_box;
    static const QString mdi_arrow_down_bold_box_outline;
    static const QString mdi_arrow_down_bold_circle;
    static const QString mdi_arrow_down_bold_circle_outline;
    static const QString mdi_arrow_down_bold_hexagon_outline;
    static const QString mdi_arrow_down_bold_outline;
    static const QString mdi_arrow_down_box;
    static const QString mdi_arrow_down_circle;
    static const QString mdi_arrow_down_circle_outline;
    static const QString mdi_arrow_down_drop_circle;
    static const QString mdi_arrow_down_drop_circle_outline;
    static const QString mdi_arrow_down_thick;
    static const QString mdi_arrow_expand;
    static const QString mdi_arrow_expand_all;
    static const QString mdi_arrow_expand_down;
    static const QString mdi_arrow_expand_horizontal;
    static const QString mdi_arrow_expand_left;
    static const QString mdi_arrow_expand_right;
    static const QString mdi_arrow_expand_up;
    static const QString mdi_arrow_expand_vertical;
    static const QString mdi_arrow_left;
    static const QString mdi_arrow_left_bold;
    static const QString mdi_arrow_left_bold_box;
    static const QString mdi_arrow_left_bold_box_outline;
    static const QString mdi_arrow_left_bold_circle;
    static const QString mdi_arrow_left_bold_circle_outline;
    static const QString mdi_arrow_left_bold_hexagon_outline;
    static const QString mdi_arrow_left_bold_outline;
    static const QString mdi_arrow_left_box;
    static const QString mdi_arrow_left_circle;
    static const QString mdi_arrow_left_circle_outline;
    static const QString mdi_arrow_left_drop_circle;
    static const QString mdi_arrow_left_drop_circle_outline;
    static const QString mdi_arrow_left_right_bold_outline;
    static const QString mdi_arrow_left_thick;
    static const QString mdi_arrow_right;
    static const QString mdi_arrow_right_bold;
    static const QString mdi_arrow_right_bold_box;
    static const QString mdi_arrow_right_bold_box_outline;
    static const QString mdi_arrow_right_bold_circle;
    static const QString mdi_arrow_right_bold_circle_outline;
    static const QString mdi_arrow_right_bold_hexagon_outline;
    static const QString mdi_arrow_right_bold_outline;
    static const QString mdi_arrow_right_box;
    static const QString mdi_arrow_right_circle;
    static const QString mdi_arrow_right_circle_outline;
    static const QString mdi_arrow_right_drop_circle;
    static const QString mdi_arrow_right_drop_circle_outline;
    static const QString mdi_arrow_right_thick;
    static const QString mdi_arrow_split_horizontal;
    static const QString mdi_arrow_split_vertical;
    static const QString mdi_arrow_top_left;
    static const QString mdi_arrow_top_left_bold_outline;
    static const QString mdi_arrow_top_left_thick;
    static const QString mdi_arrow_top_right;
    static const QString mdi_arrow_top_right_bold_outline;
    static const QString mdi_arrow_top_right_thick;
    static const QString mdi_arrow_up;
    static const QString mdi_arrow_up_bold;
    static const QString mdi_arrow_up_bold_box;
    static const QString mdi_arrow_up_bold_box_outline;
    static const QString mdi_arrow_up_bold_circle;
    static const QString mdi_arrow_up_bold_circle_outline;
    static const QString mdi_arrow_up_bold_hexagon_outline;
    static const QString mdi_arrow_up_bold_outline;
    static const QString mdi_arrow_up_box;
    static const QString mdi_arrow_up_circle;
    static const QString mdi_arrow_up_circle_outline;
    static const QString mdi_arrow_up_down_bold_outline;
    static const QString mdi_arrow_up_drop_circle;
    static const QString mdi_arrow_up_drop_circle_outline;
    static const QString mdi_arrow_up_thick;
    static const QString mdi_artist;
    static const QString mdi_artist_outline;
    static const QString mdi_artstation;
    static const QString mdi_aspect_ratio;
    static const QString mdi_assistant;
    static const QString mdi_asterisk;
    static const QString mdi_at;
    static const QString mdi_atlassian;
    static const QString mdi_atm;
    static const QString mdi_atom;
    static const QString mdi_attachment;
    static const QString mdi_audio_video;
    static const QString mdi_audiobook;
    static const QString mdi_augmented_reality;
    static const QString mdi_auto_fix;
    static const QString mdi_auto_upload;
    static const QString mdi_autorenew;
    static const QString mdi_av_timer;
    static const QString mdi_axe;
    static const QString mdi_axis;
    static const QString mdi_axis_arrow;
    static const QString mdi_axis_arrow_lock;
    static const QString mdi_axis_lock;
    static const QString mdi_axis_x_arrow;
    static const QString mdi_axis_x_arrow_lock;
    static const QString mdi_axis_x_rotate_clockwise;
    static const QString mdi_axis_x_rotate_counterclockwise;
    static const QString mdi_axis_x_y_arrow_lock;
    static const QString mdi_axis_y_arrow;
    static const QString mdi_axis_y_arrow_lock;
    static const QString mdi_axis_y_rotate_clockwise;
    static const QString mdi_axis_y_rotate_counterclockwise;
    static const QString mdi_axis_z_arrow;
    static const QString mdi_axis_z_arrow_lock;
    static const QString mdi_axis_z_rotate_clockwise;
    static const QString mdi_axis_z_rotate_counterclockwise;
    static const QString mdi_azure;
    static const QString mdi_babel;
    static const QString mdi_baby;
    static const QString mdi_baby_buggy;
    static const QString mdi_backburger;
    static const QString mdi_backspace;
    static const QString mdi_backspace_outline;
    static const QString mdi_backup_restore;
    static const QString mdi_badminton;
    static const QString mdi_balloon;
    static const QString mdi_ballot;
    static const QString mdi_ballot_outline;
    static const QString mdi_ballot_recount;
    static const QString mdi_ballot_recount_outline;
    static const QString mdi_bandage;
    static const QString mdi_bandcamp;
    static const QString mdi_bank;
    static const QString mdi_bank_minus;
    static const QString mdi_bank_plus;
    static const QString mdi_bank_remove;
    static const QString mdi_bank_transfer;
    static const QString mdi_bank_transfer_in;
    static const QString mdi_bank_transfer_out;
    static const QString mdi_barcode;
    static const QString mdi_barcode_scan;
    static const QString mdi_barley;
    static const QString mdi_barley_off;
    static const QString mdi_barn;
    static const QString mdi_barrel;
    static const QString mdi_baseball;
    static const QString mdi_baseball_bat;
    static const QString mdi_basecamp;
    static const QString mdi_basket;
    static const QString mdi_basket_fill;
    static const QString mdi_basket_unfill;
    static const QString mdi_basketball;
    static const QString mdi_basketball_hoop;
    static const QString mdi_basketball_hoop_outline;
    static const QString mdi_bat;
    static const QString mdi_battery;
    static const QString mdi_battery_10;
    static const QString mdi_battery_10_bluetooth;
    static const QString mdi_battery_20;
    static const QString mdi_battery_20_bluetooth;
    static const QString mdi_battery_30;
    static const QString mdi_battery_30_bluetooth;
    static const QString mdi_battery_40;
    static const QString mdi_battery_40_bluetooth;
    static const QString mdi_battery_50;
    static const QString mdi_battery_50_bluetooth;
    static const QString mdi_battery_60;
    static const QString mdi_battery_60_bluetooth;
    static const QString mdi_battery_70;
    static const QString mdi_battery_70_bluetooth;
    static const QString mdi_battery_80;
    static const QString mdi_battery_80_bluetooth;
    static const QString mdi_battery_90;
    static const QString mdi_battery_90_bluetooth;
    static const QString mdi_battery_alert;
    static const QString mdi_battery_alert_bluetooth;
    static const QString mdi_battery_bluetooth;
    static const QString mdi_battery_bluetooth_variant;
    static const QString mdi_battery_charging;
    static const QString mdi_battery_charging_10;
    static const QString mdi_battery_charging_100;
    static const QString mdi_battery_charging_20;
    static const QString mdi_battery_charging_30;
    static const QString mdi_battery_charging_40;
    static const QString mdi_battery_charging_50;
    static const QString mdi_battery_charging_60;
    static const QString mdi_battery_charging_70;
    static const QString mdi_battery_charging_80;
    static const QString mdi_battery_charging_90;
    static const QString mdi_battery_charging_outline;
    static const QString mdi_battery_charging_wireless;
    static const QString mdi_battery_charging_wireless_10;
    static const QString mdi_battery_charging_wireless_20;
    static const QString mdi_battery_charging_wireless_30;
    static const QString mdi_battery_charging_wireless_40;
    static const QString mdi_battery_charging_wireless_50;
    static const QString mdi_battery_charging_wireless_60;
    static const QString mdi_battery_charging_wireless_70;
    static const QString mdi_battery_charging_wireless_80;
    static const QString mdi_battery_charging_wireless_90;
    static const QString mdi_battery_charging_wireless_alert;
    static const QString mdi_battery_charging_wireless_outline;
    static const QString mdi_battery_minus;
    static const QString mdi_battery_negative;
    static const QString mdi_battery_outline;
    static const QString mdi_battery_plus;
    static const QString mdi_battery_positive;
    static const QString mdi_battery_unknown;
    static const QString mdi_battery_unknown_bluetooth;
    static const QString mdi_battlenet;
    static const QString mdi_beach;
    static const QString mdi_beaker;
    static const QString mdi_beaker_outline;
    static const QString mdi_beats;
    static const QString mdi_bed_empty;
    static const QString mdi_beer;
    static const QString mdi_behance;
    static const QString mdi_bell;
    static const QString mdi_bell_alert;
    static const QString mdi_bell_circle;
    static const QString mdi_bell_circle_outline;
    static const QString mdi_bell_off;
    static const QString mdi_bell_off_outline;
    static const QString mdi_bell_outline;
    static const QString mdi_bell_plus;
    static const QString mdi_bell_plus_outline;
    static const QString mdi_bell_ring;
    static const QString mdi_bell_ring_outline;
    static const QString mdi_bell_sleep;
    static const QString mdi_bell_sleep_outline;
    static const QString mdi_beta;
    static const QString mdi_betamax;
    static const QString mdi_bible;
    static const QString mdi_bike;
    static const QString mdi_billiards;
    static const QString mdi_billiards_rack;
    static const QString mdi_bing;
    static const QString mdi_binoculars;
    static const QString mdi_bio;
    static const QString mdi_biohazard;
    static const QString mdi_bitbucket;
    static const QString mdi_bitcoin;
    static const QString mdi_black_mesa;
    static const QString mdi_blackberry;
    static const QString mdi_blender;
    static const QString mdi_blender_software;
    static const QString mdi_blinds;
    static const QString mdi_block_helper;
    static const QString mdi_blogger;
    static const QString mdi_blood_bag;
    static const QString mdi_bluetooth;
    static const QString mdi_bluetooth_audio;
    static const QString mdi_bluetooth_connect;
    static const QString mdi_bluetooth_off;
    static const QString mdi_bluetooth_settings;
    static const QString mdi_bluetooth_transfer;
    static const QString mdi_blur;
    static const QString mdi_blur_linear;
    static const QString mdi_blur_off;
    static const QString mdi_blur_radial;
    static const QString mdi_bolnisi_cross;
    static const QString mdi_bolt;
    static const QString mdi_bomb;
    static const QString mdi_bomb_off;
    static const QString mdi_bone;
    static const QString mdi_book;
    static const QString mdi_book_lock;
    static const QString mdi_book_lock_open;
    static const QString mdi_book_minus;
    static const QString mdi_book_multiple;
    static const QString mdi_book_multiple_minus;
    static const QString mdi_book_multiple_plus;
    static const QString mdi_book_multiple_remove;
    static const QString mdi_book_multiple_variant;
    static const QString mdi_book_open;
    static const QString mdi_book_open_outline;
    static const QString mdi_book_open_page_variant;
    static const QString mdi_book_open_variant;
    static const QString mdi_book_outline;
    static const QString mdi_book_plus;
    static const QString mdi_book_remove;
    static const QString mdi_book_variant;
    static const QString mdi_bookmark;
    static const QString mdi_bookmark_check;
    static const QString mdi_bookmark_minus;
    static const QString mdi_bookmark_minus_outline;
    static const QString mdi_bookmark_music;
    static const QString mdi_bookmark_off;
    static const QString mdi_bookmark_off_outline;
    static const QString mdi_bookmark_outline;
    static const QString mdi_bookmark_plus;
    static const QString mdi_bookmark_plus_outline;
    static const QString mdi_bookmark_remove;
    static const QString mdi_boombox;
    static const QString mdi_bootstrap;
    static const QString mdi_border_all;
    static const QString mdi_border_all_variant;
    static const QString mdi_border_bottom;
    static const QString mdi_border_bottom_variant;
    static const QString mdi_border_color;
    static const QString mdi_border_horizontal;
    static const QString mdi_border_inside;
    static const QString mdi_border_left;
    static const QString mdi_border_left_variant;
    static const QString mdi_border_none;
    static const QString mdi_border_none_variant;
    static const QString mdi_border_outside;
    static const QString mdi_border_right;
    static const QString mdi_border_right_variant;
    static const QString mdi_border_style;
    static const QString mdi_border_top;
    static const QString mdi_border_top_variant;
    static const QString mdi_border_vertical;
    static const QString mdi_bottle_wine;
    static const QString mdi_bow_tie;
    static const QString mdi_bowl;
    static const QString mdi_bowling;
    static const QString mdi_box;
    static const QString mdi_box_cutter;
    static const QString mdi_box_shadow;
    static const QString mdi_boxing_glove;
    static const QString mdi_braille;
    static const QString mdi_brain;
    static const QString mdi_bread_slice;
    static const QString mdi_bread_slice_outline;
    static const QString mdi_bridge;
    static const QString mdi_briefcase;
    static const QString mdi_briefcase_account;
    static const QString mdi_briefcase_account_outline;
    static const QString mdi_briefcase_check;
    static const QString mdi_briefcase_download;
    static const QString mdi_briefcase_download_outline;
    static const QString mdi_briefcase_edit;
    static const QString mdi_briefcase_edit_outline;
    static const QString mdi_briefcase_minus;
    static const QString mdi_briefcase_minus_outline;
    static const QString mdi_briefcase_outline;
    static const QString mdi_briefcase_plus;
    static const QString mdi_briefcase_plus_outline;
    static const QString mdi_briefcase_remove;
    static const QString mdi_briefcase_remove_outline;
    static const QString mdi_briefcase_search;
    static const QString mdi_briefcase_search_outline;
    static const QString mdi_briefcase_upload;
    static const QString mdi_briefcase_upload_outline;
    static const QString mdi_brightness_1;
    static const QString mdi_brightness_2;
    static const QString mdi_brightness_3;
    static const QString mdi_brightness_4;
    static const QString mdi_brightness_5;
    static const QString mdi_brightness_6;
    static const QString mdi_brightness_7;
    static const QString mdi_brightness_auto;
    static const QString mdi_brightness_percent;
    static const QString mdi_broom;
    static const QString mdi_brush;
    static const QString mdi_buddhism;
    static const QString mdi_buffer;
    static const QString mdi_bug;
    static const QString mdi_bug_check;
    static const QString mdi_bug_check_outline;
    static const QString mdi_bug_outline;
    static const QString mdi_bugle;
    static const QString mdi_bulldozer;
    static const QString mdi_bullet;
    static const QString mdi_bulletin_board;
    static const QString mdi_bullhorn;
    static const QString mdi_bullhorn_outline;
    static const QString mdi_bullseye;
    static const QString mdi_bullseye_arrow;
    static const QString mdi_bus;
    static const QString mdi_bus_alert;
    static const QString mdi_bus_articulated_end;
    static const QString mdi_bus_articulated_front;
    static const QString mdi_bus_clock;
    static const QString mdi_bus_double_decker;
    static const QString mdi_bus_school;
    static const QString mdi_bus_side;
    static const QString mdi_cached;
    static const QString mdi_cactus;
    static const QString mdi_cake;
    static const QString mdi_cake_layered;
    static const QString mdi_cake_variant;
    static const QString mdi_calculator;
    static const QString mdi_calculator_variant;
    static const QString mdi_calendar;
    static const QString mdi_calendar_alert;
    static const QString mdi_calendar_blank;
    static const QString mdi_calendar_blank_outline;
    static const QString mdi_calendar_check;
    static const QString mdi_calendar_check_outline;
    static const QString mdi_calendar_clock;
    static const QString mdi_calendar_edit;
    static const QString mdi_calendar_export;
    static const QString mdi_calendar_heart;
    static const QString mdi_calendar_import;
    static const QString mdi_calendar_minus;
    static const QString mdi_calendar_multiple;
    static const QString mdi_calendar_multiple_check;
    static const QString mdi_calendar_multiselect;
    static const QString mdi_calendar_outline;
    static const QString mdi_calendar_plus;
    static const QString mdi_calendar_question;
    static const QString mdi_calendar_range;
    static const QString mdi_calendar_range_outline;
    static const QString mdi_calendar_remove;
    static const QString mdi_calendar_remove_outline;
    static const QString mdi_calendar_search;
    static const QString mdi_calendar_star;
    static const QString mdi_calendar_text;
    static const QString mdi_calendar_text_outline;
    static const QString mdi_calendar_today;
    static const QString mdi_calendar_week;
    static const QString mdi_calendar_week_begin;
    static const QString mdi_call_made;
    static const QString mdi_call_merge;
    static const QString mdi_call_missed;
    static const QString mdi_call_received;
    static const QString mdi_call_split;
    static const QString mdi_camcorder;
    static const QString mdi_camcorder_box;
    static const QString mdi_camcorder_box_off;
    static const QString mdi_camcorder_off;
    static const QString mdi_camera;
    static const QString mdi_camera_account;
    static const QString mdi_camera_burst;
    static const QString mdi_camera_control;
    static const QString mdi_camera_enhance;
    static const QString mdi_camera_enhance_outline;
    static const QString mdi_camera_front;
    static const QString mdi_camera_front_variant;
    static const QString mdi_camera_gopro;
    static const QString mdi_camera_image;
    static const QString mdi_camera_iris;
    static const QString mdi_camera_metering_center;
    static const QString mdi_camera_metering_matrix;
    static const QString mdi_camera_metering_partial;
    static const QString mdi_camera_metering_spot;
    static const QString mdi_camera_off;
    static const QString mdi_camera_outline;
    static const QString mdi_camera_party_mode;
    static const QString mdi_camera_rear;
    static const QString mdi_camera_rear_variant;
    static const QString mdi_camera_switch;
    static const QString mdi_camera_timer;
    static const QString mdi_camera_wireless;
    static const QString mdi_camera_wireless_outline;
    static const QString mdi_cancel;
    static const QString mdi_candle;
    static const QString mdi_candycane;
//    static const QString mdi_cannabis;
    static const QString mdi_caps_lock;
    static const QString mdi_car;
    static const QString mdi_car_battery;
    static const QString mdi_car_brake_abs;
    static const QString mdi_car_brake_alert;
    static const QString mdi_car_brake_hold;
    static const QString mdi_car_brake_parking;
    static const QString mdi_car_connected;
    static const QString mdi_car_convertible;
    static const QString mdi_car_cruise_control;
    static const QString mdi_car_defrost_front;
    static const QString mdi_car_defrost_rear;
    static const QString mdi_car_door;
    static const QString mdi_car_electric;
    static const QString mdi_car_esp;
    static const QString mdi_car_estate;
    static const QString mdi_car_hatchback;
    static const QString mdi_car_key;
    static const QString mdi_car_light_dimmed;
    static const QString mdi_car_light_fog;
    static const QString mdi_car_light_high;
    static const QString mdi_car_limousine;
    static const QString mdi_car_multiple;
    static const QString mdi_car_parking_lights;
    static const QString mdi_car_pickup;
    static const QString mdi_car_side;
    static const QString mdi_car_sports;
    static const QString mdi_car_tire_alert;
    static const QString mdi_car_traction_control;
    static const QString mdi_car_wash;
    static const QString mdi_caravan;
    static const QString mdi_card;
    static const QString mdi_card_bulleted;
    static const QString mdi_card_bulleted_off;
    static const QString mdi_card_bulleted_off_outline;
    static const QString mdi_card_bulleted_outline;
    static const QString mdi_card_bulleted_settings;
    static const QString mdi_card_bulleted_settings_outline;
    static const QString mdi_card_outline;
    static const QString mdi_card_text;
    static const QString mdi_card_text_outline;
    static const QString mdi_cards;
    static const QString mdi_cards_club;
    static const QString mdi_cards_diamond;
    static const QString mdi_cards_heart;
    static const QString mdi_cards_outline;
    static const QString mdi_cards_playing_outline;
    static const QString mdi_cards_spade;
    static const QString mdi_cards_variant;
    static const QString mdi_carrot;
    static const QString mdi_carry_on_bag_check;
    static const QString mdi_cart;
    static const QString mdi_cart_arrow_down;
    static const QString mdi_cart_arrow_right;
    static const QString mdi_cart_arrow_up;
    static const QString mdi_cart_minus;
    static const QString mdi_cart_off;
    static const QString mdi_cart_outline;
    static const QString mdi_cart_plus;
    static const QString mdi_cart_remove;
    static const QString mdi_case_sensitive_alt;
    static const QString mdi_cash;
    static const QString mdi_cash_100;
    static const QString mdi_cash_marker;
    static const QString mdi_cash_multiple;
    static const QString mdi_cash_refund;
    static const QString mdi_cash_register;
    static const QString mdi_cash_usd;
    static const QString mdi_cassette;
    static const QString mdi_cast;
    static const QString mdi_cast_connected;
    static const QString mdi_cast_off;
    static const QString mdi_castle;
    static const QString mdi_cat;
    static const QString mdi_cctv;
    static const QString mdi_ceiling_light;
    static const QString mdi_cellphone;
    static const QString mdi_cellphone_android;
    static const QString mdi_cellphone_arrow_down;
    static const QString mdi_cellphone_basic;
    static const QString mdi_cellphone_dock;
    static const QString mdi_cellphone_erase;
    static const QString mdi_cellphone_iphone;
    static const QString mdi_cellphone_key;
    static const QString mdi_cellphone_link;
    static const QString mdi_cellphone_link_off;
    static const QString mdi_cellphone_lock;
    static const QString mdi_cellphone_message;
    static const QString mdi_cellphone_off;
    static const QString mdi_cellphone_screenshot;
    static const QString mdi_cellphone_settings;
    static const QString mdi_cellphone_settings_variant;
    static const QString mdi_cellphone_sound;
    static const QString mdi_cellphone_text;
    static const QString mdi_cellphone_wireless;
    static const QString mdi_celtic_cross;
    static const QString mdi_certificate;
    static const QString mdi_chair_school;
    static const QString mdi_charity;
    static const QString mdi_chart_arc;
    static const QString mdi_chart_areaspline;
    static const QString mdi_chart_bar;
    static const QString mdi_chart_bar_stacked;
    static const QString mdi_chart_bell_curve;
    static const QString mdi_chart_bubble;
    static const QString mdi_chart_donut;
    static const QString mdi_chart_donut_variant;
    static const QString mdi_chart_gantt;
    static const QString mdi_chart_histogram;
    static const QString mdi_chart_line;
    static const QString mdi_chart_line_stacked;
    static const QString mdi_chart_line_variant;
    static const QString mdi_chart_multiline;
    static const QString mdi_chart_pie;
    static const QString mdi_chart_scatterplot_hexbin;
    static const QString mdi_chart_timeline;
    static const QString mdi_chat;
    static const QString mdi_chat_alert;
    static const QString mdi_chat_processing;
    static const QString mdi_check;
    static const QString mdi_check_all;
    static const QString mdi_check_box_multiple_outline;
    static const QString mdi_check_box_outline;
    static const QString mdi_check_circle;
    static const QString mdi_check_circle_outline;
    static const QString mdi_check_decagram;
    static const QString mdi_check_network;
    static const QString mdi_check_network_outline;
    static const QString mdi_check_outline;
    static const QString mdi_checkbook;
    static const QString mdi_checkbox_blank;
    static const QString mdi_checkbox_blank_circle;
    static const QString mdi_checkbox_blank_circle_outline;
    static const QString mdi_checkbox_blank_outline;
    static const QString mdi_checkbox_intermediate;
    static const QString mdi_checkbox_marked;
    static const QString mdi_checkbox_marked_circle;
    static const QString mdi_checkbox_marked_circle_outline;
    static const QString mdi_checkbox_marked_outline;
    static const QString mdi_checkbox_multiple_blank;
    static const QString mdi_checkbox_multiple_blank_circle;
    static const QString mdi_checkbox_multiple_blank_circle_outline;
    static const QString mdi_checkbox_multiple_blank_outline;
    static const QString mdi_checkbox_multiple_marked;
    static const QString mdi_checkbox_multiple_marked_circle;
    static const QString mdi_checkbox_multiple_marked_circle_outline;
    static const QString mdi_checkbox_multiple_marked_outline;
    static const QString mdi_checkerboard;
    static const QString mdi_chef_hat;
    static const QString mdi_chemical_weapon;
    static const QString mdi_chess_bishop;
    static const QString mdi_chess_king;
    static const QString mdi_chess_knight;
    static const QString mdi_chess_pawn;
    static const QString mdi_chess_queen;
    static const QString mdi_chess_rook;
    static const QString mdi_chevron_double_down;
    static const QString mdi_chevron_double_left;
    static const QString mdi_chevron_double_right;
    static const QString mdi_chevron_double_up;
    static const QString mdi_chevron_down;
    static const QString mdi_chevron_down_box;
    static const QString mdi_chevron_down_box_outline;
    static const QString mdi_chevron_down_circle;
    static const QString mdi_chevron_down_circle_outline;
    static const QString mdi_chevron_left;
    static const QString mdi_chevron_left_box;
    static const QString mdi_chevron_left_box_outline;
    static const QString mdi_chevron_left_circle;
    static const QString mdi_chevron_left_circle_outline;
    static const QString mdi_chevron_right;
    static const QString mdi_chevron_right_box;
    static const QString mdi_chevron_right_box_outline;
    static const QString mdi_chevron_right_circle;
    static const QString mdi_chevron_right_circle_outline;
    static const QString mdi_chevron_triple_down;
    static const QString mdi_chevron_triple_left;
    static const QString mdi_chevron_triple_right;
    static const QString mdi_chevron_triple_up;
    static const QString mdi_chevron_up;
    static const QString mdi_chevron_up_box;
    static const QString mdi_chevron_up_box_outline;
    static const QString mdi_chevron_up_circle;
    static const QString mdi_chevron_up_circle_outline;
    static const QString mdi_chili_hot;
    static const QString mdi_chili_medium;
    static const QString mdi_chili_mild;
    static const QString mdi_chip;
    static const QString mdi_christianity;
    static const QString mdi_christianity_outline;
    static const QString mdi_church;
    static const QString mdi_circle;
    static const QString mdi_circle_edit_outline;
    static const QString mdi_circle_medium;
    static const QString mdi_circle_outline;
    static const QString mdi_circle_slice_1;
    static const QString mdi_circle_slice_2;
    static const QString mdi_circle_slice_3;
    static const QString mdi_circle_slice_4;
    static const QString mdi_circle_slice_5;
    static const QString mdi_circle_slice_6;
    static const QString mdi_circle_slice_7;
    static const QString mdi_circle_slice_8;
    static const QString mdi_circle_small;
    static const QString mdi_cisco_webex;
    static const QString mdi_city;
    static const QString mdi_city_variant;
    static const QString mdi_city_variant_outline;
    static const QString mdi_clipboard;
    static const QString mdi_clipboard_account;
    static const QString mdi_clipboard_account_outline;
    static const QString mdi_clipboard_alert;
    static const QString mdi_clipboard_alert_outline;
    static const QString mdi_clipboard_arrow_down;
    static const QString mdi_clipboard_arrow_down_outline;
    static const QString mdi_clipboard_arrow_left;
    static const QString mdi_clipboard_arrow_left_outline;
    static const QString mdi_clipboard_arrow_right;
    static const QString mdi_clipboard_arrow_right_outline;
    static const QString mdi_clipboard_arrow_up;
    static const QString mdi_clipboard_arrow_up_outline;
    static const QString mdi_clipboard_check;
    static const QString mdi_clipboard_check_outline;
    static const QString mdi_clipboard_flow;
    static const QString mdi_clipboard_outline;
    static const QString mdi_clipboard_play;
    static const QString mdi_clipboard_play_outline;
    static const QString mdi_clipboard_plus;
    static const QString mdi_clipboard_pulse;
    static const QString mdi_clipboard_pulse_outline;
    static const QString mdi_clipboard_text;
    static const QString mdi_clipboard_text_outline;
    static const QString mdi_clipboard_text_play;
    static const QString mdi_clipboard_text_play_outline;
    static const QString mdi_clippy;
    static const QString mdi_clock;
    static const QString mdi_clock_alert;
    static const QString mdi_clock_alert_outline;
    static const QString mdi_clock_end;
    static const QString mdi_clock_fast;
    static const QString mdi_clock_in;
    static const QString mdi_clock_out;
//    static const QString mdi_clock_outline;
    static const QString mdi_clock_start;
    static const QString mdi_close;
    static const QString mdi_close_box;
    static const QString mdi_close_box_multiple;
    static const QString mdi_close_box_multiple_outline;
    static const QString mdi_close_box_outline;
    static const QString mdi_close_circle;
    static const QString mdi_close_circle_outline;
    static const QString mdi_close_network;
    static const QString mdi_close_network_outline;
    static const QString mdi_close_octagon;
    static const QString mdi_close_octagon_outline;
    static const QString mdi_close_outline;
    static const QString mdi_closed_caption;
    static const QString mdi_closed_caption_outline;
    static const QString mdi_cloud;
    static const QString mdi_cloud_alert;
    static const QString mdi_cloud_braces;
    static const QString mdi_cloud_check;
    static const QString mdi_cloud_circle;
    static const QString mdi_cloud_download;
    static const QString mdi_cloud_download_outline;
    static const QString mdi_cloud_off_outline;
    static const QString mdi_cloud_outline;
    static const QString mdi_cloud_print;
    static const QString mdi_cloud_print_outline;
    static const QString mdi_cloud_question;
    static const QString mdi_cloud_search;
    static const QString mdi_cloud_search_outline;
    static const QString mdi_cloud_sync;
    static const QString mdi_cloud_tags;
    static const QString mdi_cloud_upload;
    static const QString mdi_cloud_upload_outline;
    static const QString mdi_clover;
    static const QString mdi_code_array;
    static const QString mdi_code_braces;
    static const QString mdi_code_brackets;
    static const QString mdi_code_equal;
    static const QString mdi_code_greater_than;
    static const QString mdi_code_greater_than_or_equal;
    static const QString mdi_code_less_than;
    static const QString mdi_code_less_than_or_equal;
    static const QString mdi_code_not_equal;
    static const QString mdi_code_not_equal_variant;
    static const QString mdi_code_parentheses;
    static const QString mdi_code_string;
    static const QString mdi_code_tags;
    static const QString mdi_code_tags_check;
    static const QString mdi_codepen;
    static const QString mdi_coffee;
    static const QString mdi_coffee_outline;
    static const QString mdi_coffee_to_go;
    static const QString mdi_coffin;
    static const QString mdi_cogs;
    static const QString mdi_coin;
    static const QString mdi_coins;
    static const QString mdi_collage;
    static const QString mdi_collapse_all;
    static const QString mdi_collapse_all_outline;
    static const QString mdi_color_helper;
    static const QString mdi_comment;
    static const QString mdi_comment_account;
    static const QString mdi_comment_account_outline;
    static const QString mdi_comment_alert;
    static const QString mdi_comment_alert_outline;
    static const QString mdi_comment_arrow_left;
    static const QString mdi_comment_arrow_left_outline;
    static const QString mdi_comment_arrow_right;
    static const QString mdi_comment_arrow_right_outline;
    static const QString mdi_comment_check;
    static const QString mdi_comment_check_outline;
    static const QString mdi_comment_eye;
    static const QString mdi_comment_eye_outline;
    static const QString mdi_comment_multiple;
    static const QString mdi_comment_multiple_outline;
    static const QString mdi_comment_outline;
    static const QString mdi_comment_plus;
    static const QString mdi_comment_plus_outline;
    static const QString mdi_comment_processing;
    static const QString mdi_comment_processing_outline;
    static const QString mdi_comment_question;
    static const QString mdi_comment_question_outline;
    static const QString mdi_comment_remove;
    static const QString mdi_comment_remove_outline;
    static const QString mdi_comment_search;
    static const QString mdi_comment_search_outline;
    static const QString mdi_comment_text;
    static const QString mdi_comment_text_multiple;
    static const QString mdi_comment_text_multiple_outline;
    static const QString mdi_comment_text_outline;
    static const QString mdi_compare;
    static const QString mdi_compass;
    static const QString mdi_compass_off;
    static const QString mdi_compass_off_outline;
    static const QString mdi_compass_outline;
    static const QString mdi_console;
    static const QString mdi_console_line;
    static const QString mdi_console_network;
    static const QString mdi_console_network_outline;
    static const QString mdi_contact_mail;
    static const QString mdi_contactless_payment;
    static const QString mdi_contacts;
    static const QString mdi_contain;
    static const QString mdi_contain_end;
    static const QString mdi_contain_start;
    static const QString mdi_content_copy;
    static const QString mdi_content_cut;
    static const QString mdi_content_duplicate;
    static const QString mdi_content_paste;
    static const QString mdi_content_save;
    static const QString mdi_content_save_all;
    static const QString mdi_content_save_edit;
    static const QString mdi_content_save_edit_outline;
    static const QString mdi_content_save_outline;
    static const QString mdi_content_save_settings;
    static const QString mdi_content_save_settings_outline;
    static const QString mdi_contrast;
    static const QString mdi_contrast_box;
    static const QString mdi_contrast_circle;
    static const QString mdi_controller_classic;
    static const QString mdi_controller_classic_outline;
    static const QString mdi_cookie;
    static const QString mdi_copyright;
    static const QString mdi_cordova;
    static const QString mdi_corn;
    static const QString mdi_counter;
    static const QString mdi_cow;
    static const QString mdi_crane;
    static const QString mdi_creation;
    static const QString mdi_creative_commons;
    static const QString mdi_credit_card;
    static const QString mdi_credit_card_marker;
    static const QString mdi_credit_card_multiple;
    static const QString mdi_credit_card_off;
    static const QString mdi_credit_card_plus;
    static const QString mdi_credit_card_refund;
    static const QString mdi_credit_card_scan;
    static const QString mdi_credit_card_settings;
    static const QString mdi_credit_card_wireless;
    static const QString mdi_cricket;
    static const QString mdi_crop;
    static const QString mdi_crop_free;
    static const QString mdi_crop_landscape;
    static const QString mdi_crop_portrait;
    static const QString mdi_crop_rotate;
    static const QString mdi_crop_square;
    static const QString mdi_crosshairs;
    static const QString mdi_crosshairs_gps;
    static const QString mdi_crown;
    static const QString mdi_cryengine;
    static const QString mdi_crystal_ball;
    static const QString mdi_cube;
    static const QString mdi_cube_outline;
    static const QString mdi_cube_scan;
    static const QString mdi_cube_send;
    static const QString mdi_cube_unfolded;
    static const QString mdi_cup;
    static const QString mdi_cup_off;
    static const QString mdi_cup_water;
    static const QString mdi_cupcake;
    static const QString mdi_curling;
    static const QString mdi_currency_bdt;
    static const QString mdi_currency_brl;
    static const QString mdi_currency_btc;
    static const QString mdi_currency_chf;
    static const QString mdi_currency_cny;
    static const QString mdi_currency_eth;
    static const QString mdi_currency_eur;
    static const QString mdi_currency_gbp;
    static const QString mdi_currency_ils;
    static const QString mdi_currency_inr;
    static const QString mdi_currency_jpy;
    static const QString mdi_currency_krw;
    static const QString mdi_currency_kzt;
    static const QString mdi_currency_ngn;
    static const QString mdi_currency_php;
    static const QString mdi_currency_rub;
    static const QString mdi_currency_sign;
    static const QString mdi_currency_try;
    static const QString mdi_currency_twd;
    static const QString mdi_currency_usd;
    static const QString mdi_currency_usd_off;
    static const QString mdi_current_ac;
    static const QString mdi_current_dc;
    static const QString mdi_cursor_default;
    static const QString mdi_cursor_default_click;
    static const QString mdi_cursor_default_click_outline;
    static const QString mdi_cursor_default_outline;
    static const QString mdi_cursor_move;
    static const QString mdi_cursor_pointer;
    static const QString mdi_cursor_text;
    static const QString mdi_database;
    static const QString mdi_database_check;
    static const QString mdi_database_edit;
    static const QString mdi_database_export;
    static const QString mdi_database_import;
    static const QString mdi_database_lock;
    static const QString mdi_database_minus;
    static const QString mdi_database_plus;
    static const QString mdi_database_refresh;
    static const QString mdi_database_remove;
    static const QString mdi_database_search;
    static const QString mdi_database_settings;
    static const QString mdi_death_star;
    static const QString mdi_death_star_variant;
    static const QString mdi_deathly_hallows;
    static const QString mdi_debian;
    static const QString mdi_debug_step_into;
    static const QString mdi_debug_step_out;
    static const QString mdi_debug_step_over;
    static const QString mdi_decagram;
    static const QString mdi_decagram_outline;
    static const QString mdi_decimal_decrease;
    static const QString mdi_decimal_increase;
    static const QString mdi_delete;
    static const QString mdi_delete_circle;
    static const QString mdi_delete_circle_outline;
    static const QString mdi_delete_empty;
    static const QString mdi_delete_forever;
    static const QString mdi_delete_forever_outline;
    static const QString mdi_delete_outline;
    static const QString mdi_delete_restore;
    static const QString mdi_delete_sweep;
    static const QString mdi_delete_sweep_outline;
    static const QString mdi_delete_variant;
    static const QString mdi_delta;
    static const QString mdi_desk_lamp;
    static const QString mdi_deskphone;
    static const QString mdi_desktop_classic;
    static const QString mdi_desktop_mac;
    static const QString mdi_desktop_mac_dashboard;
    static const QString mdi_desktop_tower;
    static const QString mdi_desktop_tower_monitor;
    static const QString mdi_details;
    static const QString mdi_dev_to;
    static const QString mdi_developer_board;
    static const QString mdi_deviantart;
    static const QString mdi_dialpad;
    static const QString mdi_diameter;
    static const QString mdi_diameter_outline;
    static const QString mdi_diameter_variant;
    static const QString mdi_diamond;
    static const QString mdi_diamond_outline;
    static const QString mdi_diamond_stone;
    static const QString mdi_dice_1;
    static const QString mdi_dice_2;
    static const QString mdi_dice_3;
    static const QString mdi_dice_4;
    static const QString mdi_dice_5;
    static const QString mdi_dice_6;
    static const QString mdi_dice_d10;
    static const QString mdi_dice_d12;
    static const QString mdi_dice_d20;
    static const QString mdi_dice_d4;
    static const QString mdi_dice_d6;
    static const QString mdi_dice_d8;
    static const QString mdi_dice_multiple;
    static const QString mdi_dictionary;
    static const QString mdi_dip_switch;
    static const QString mdi_directions;
    static const QString mdi_directions_fork;
    static const QString mdi_disc;
    static const QString mdi_disc_alert;
    static const QString mdi_disc_player;
    static const QString mdi_discord;
    static const QString mdi_dishwasher;
    static const QString mdi_disqus;
    static const QString mdi_disqus_outline;
    static const QString mdi_diving_flippers;
    static const QString mdi_diving_helmet;
    static const QString mdi_diving_scuba;
    static const QString mdi_diving_scuba_flag;
    static const QString mdi_diving_scuba_tank;
    static const QString mdi_diving_scuba_tank_multiple;
    static const QString mdi_diving_snorkel;
    static const QString mdi_division;
    static const QString mdi_division_box;
    static const QString mdi_dlna;
    static const QString mdi_dna;
    static const QString mdi_dns;
    static const QString mdi_dns_outline;
    static const QString mdi_do_not_disturb;
    static const QString mdi_do_not_disturb_off;
    static const QString mdi_docker;
    static const QString mdi_doctor;
    static const QString mdi_dog;
    static const QString mdi_dog_service;
    static const QString mdi_dog_side;
    static const QString mdi_dolby;
    static const QString mdi_domain;
    static const QString mdi_domain_off;
    static const QString mdi_donkey;
    static const QString mdi_door;
    static const QString mdi_door_closed;
    static const QString mdi_door_open;
    static const QString mdi_doorbell_video;
    static const QString mdi_dot_net;
    static const QString mdi_dots_horizontal;
    static const QString mdi_dots_horizontal_circle;
    static const QString mdi_dots_horizontal_circle_outline;
    static const QString mdi_dots_vertical;
    static const QString mdi_dots_vertical_circle;
    static const QString mdi_dots_vertical_circle_outline;
    static const QString mdi_douban;
    static const QString mdi_download;
    static const QString mdi_download_multiple;
    static const QString mdi_download_network;
    static const QString mdi_download_network_outline;
    static const QString mdi_download_outline;
    static const QString mdi_drag;
    static const QString mdi_drag_horizontal;
    static const QString mdi_drag_variant;
    static const QString mdi_drag_vertical;
    static const QString mdi_drama_masks;
    static const QString mdi_drawing;
    static const QString mdi_drawing_box;
    static const QString mdi_dribbble;
    static const QString mdi_dribbble_box;
    static const QString mdi_drone;
    static const QString mdi_dropbox;
    static const QString mdi_drupal;
    static const QString mdi_duck;
    static const QString mdi_dumbbell;
    static const QString mdi_dump_truck;
    static const QString mdi_ear_hearing;
    static const QString mdi_ear_hearing_off;
    static const QString mdi_earth;
    static const QString mdi_earth_box;
    static const QString mdi_earth_box_off;
    static const QString mdi_earth_off;
    static const QString mdi_edge;
    static const QString mdi_egg;
    static const QString mdi_egg_easter;
    static const QString mdi_eight_track;
    static const QString mdi_eject;
    static const QString mdi_eject_outline;
    static const QString mdi_elephant;
    static const QString mdi_elevation_decline;
    static const QString mdi_elevation_rise;
    static const QString mdi_elevator;
    static const QString mdi_email;
    static const QString mdi_email_alert;
    static const QString mdi_email_box;
    static const QString mdi_email_check;
    static const QString mdi_email_check_outline;
    static const QString mdi_email_lock;
    static const QString mdi_email_mark_as_unread;
    static const QString mdi_email_open;
    static const QString mdi_email_open_outline;
    static const QString mdi_email_outline;
    static const QString mdi_email_plus;
    static const QString mdi_email_plus_outline;
    static const QString mdi_email_search;
    static const QString mdi_email_search_outline;
    static const QString mdi_email_variant;
    static const QString mdi_ember;
    static const QString mdi_emby;
    static const QString mdi_emoticon;
    static const QString mdi_emoticon_angry;
    static const QString mdi_emoticon_angry_outline;
    static const QString mdi_emoticon_cool;
    static const QString mdi_emoticon_cool_outline;
    static const QString mdi_emoticon_cry;
    static const QString mdi_emoticon_cry_outline;
    static const QString mdi_emoticon_dead;
    static const QString mdi_emoticon_dead_outline;
    static const QString mdi_emoticon_devil;
    static const QString mdi_emoticon_devil_outline;
    static const QString mdi_emoticon_excited;
    static const QString mdi_emoticon_excited_outline;
    static const QString mdi_emoticon_happy;
    static const QString mdi_emoticon_happy_outline;
    static const QString mdi_emoticon_kiss;
    static const QString mdi_emoticon_kiss_outline;
    static const QString mdi_emoticon_neutral;
    static const QString mdi_emoticon_neutral_outline;
    static const QString mdi_emoticon_outline;
    static const QString mdi_emoticon_poop;
    static const QString mdi_emoticon_poop_outline;
    static const QString mdi_emoticon_sad;
    static const QString mdi_emoticon_sad_outline;
    static const QString mdi_emoticon_tongue;
    static const QString mdi_emoticon_tongue_outline;
    static const QString mdi_emoticon_wink;
    static const QString mdi_emoticon_wink_outline;
    static const QString mdi_engine;
    static const QString mdi_engine_off;
    static const QString mdi_engine_off_outline;
    static const QString mdi_engine_outline;
    static const QString mdi_equal;
    static const QString mdi_equal_box;
    static const QString mdi_eraser;
    static const QString mdi_eraser_variant;
    static const QString mdi_escalator;
    static const QString mdi_eslint;
    static const QString mdi_et;
    static const QString mdi_ethereum;
    static const QString mdi_ethernet;
    static const QString mdi_ethernet_cable;
    static const QString mdi_ethernet_cable_off;
    static const QString mdi_etsy;
    static const QString mdi_ev_station;
    static const QString mdi_eventbrite;
    static const QString mdi_evernote;
    static const QString mdi_exclamation;
    static const QString mdi_exit_run;
    static const QString mdi_exit_to_app;
    static const QString mdi_expand_all;
    static const QString mdi_expand_all_outline;
    static const QString mdi_exponent;
    static const QString mdi_exponent_box;
    static const QString mdi_export;
    static const QString mdi_export_variant;
    static const QString mdi_eye;
    static const QString mdi_eye_check;
    static const QString mdi_eye_check_outline;
    static const QString mdi_eye_circle;
    static const QString mdi_eye_circle_outline;
    static const QString mdi_eye_off;
    static const QString mdi_eye_off_outline;
    static const QString mdi_eye_outline;
    static const QString mdi_eye_plus;
    static const QString mdi_eye_plus_outline;
    static const QString mdi_eye_settings;
    static const QString mdi_eye_settings_outline;
    static const QString mdi_eyedropper;
    static const QString mdi_eyedropper_variant;
    static const QString mdi_face;
    static const QString mdi_face_agent;
    static const QString mdi_face_outline;
    static const QString mdi_face_profile;
    static const QString mdi_face_recognition;
    static const QString mdi_facebook;
    static const QString mdi_facebook_box;
    static const QString mdi_facebook_messenger;
    static const QString mdi_facebook_workplace;
    static const QString mdi_factory;
    static const QString mdi_fan;
    static const QString mdi_fan_off;
    static const QString mdi_fast_forward;
    static const QString mdi_fast_forward_10;
    static const QString mdi_fast_forward_30;
    static const QString mdi_fast_forward_outline;
    static const QString mdi_fax;
    static const QString mdi_feather;
    static const QString mdi_feature_search;
    static const QString mdi_feature_search_outline;
    static const QString mdi_fedora;
    static const QString mdi_ferry;
    static const QString mdi_file;
    static const QString mdi_file_account;
    static const QString mdi_file_alert;
    static const QString mdi_file_alert_outline;
    static const QString mdi_file_cabinet;
    static const QString mdi_file_cancel;
    static const QString mdi_file_cancel_outline;
    static const QString mdi_file_chart;
    static const QString mdi_file_check;
    static const QString mdi_file_cloud;
    static const QString mdi_file_compare;
    static const QString mdi_file_delimited;
    static const QString mdi_file_document;
    static const QString mdi_file_document_box;
    static const QString mdi_file_document_box_multiple;
    static const QString mdi_file_document_box_multiple_outline;
    static const QString mdi_file_document_box_outline;
    static const QString mdi_file_document_edit;
    static const QString mdi_file_document_edit_outline;
    static const QString mdi_file_document_outline;
    static const QString mdi_file_download;
    static const QString mdi_file_download_outline;
    static const QString mdi_file_excel;
    static const QString mdi_file_excel_box;
    static const QString mdi_file_export;
    static const QString mdi_file_eye;
    static const QString mdi_file_eye_outline;
    static const QString mdi_file_find;
    static const QString mdi_file_find_outline;
    static const QString mdi_file_hidden;
    static const QString mdi_file_image;
    static const QString mdi_file_import;
    static const QString mdi_file_lock;
    static const QString mdi_file_move;
    static const QString mdi_file_multiple;
    static const QString mdi_file_music;
    static const QString mdi_file_outline;
    static const QString mdi_file_pdf;
    static const QString mdi_file_pdf_box;
    static const QString mdi_file_percent;
    static const QString mdi_file_plus;
    static const QString mdi_file_powerpoint;
    static const QString mdi_file_powerpoint_box;
    static const QString mdi_file_presentation_box;
    static const QString mdi_file_question;
    static const QString mdi_file_remove;
    static const QString mdi_file_replace;
    static const QString mdi_file_replace_outline;
    static const QString mdi_file_restore;
    static const QString mdi_file_search;
    static const QString mdi_file_search_outline;
    static const QString mdi_file_send;
    static const QString mdi_file_table;
    static const QString mdi_file_table_outline;
    static const QString mdi_file_tree;
    static const QString mdi_file_undo;
    static const QString mdi_file_upload;
    static const QString mdi_file_upload_outline;
    static const QString mdi_file_video;
    static const QString mdi_file_word;
    static const QString mdi_file_word_box;
    static const QString mdi_file_xml;
    static const QString mdi_film;
    static const QString mdi_filmstrip;
    static const QString mdi_filmstrip_off;
    static const QString mdi_filter;
    static const QString mdi_filter_outline;
    static const QString mdi_filter_remove;
    static const QString mdi_filter_remove_outline;
    static const QString mdi_filter_variant;
    static const QString mdi_finance;
    static const QString mdi_find_replace;
    static const QString mdi_fingerprint;
    static const QString mdi_fire;
    static const QString mdi_fire_truck;
    static const QString mdi_firebase;
    static const QString mdi_firefox;
    static const QString mdi_fish;
    static const QString mdi_flag;
    static const QString mdi_flag_checkered;
    static const QString mdi_flag_minus;
    static const QString mdi_flag_outline;
    static const QString mdi_flag_plus;
    static const QString mdi_flag_remove;
    static const QString mdi_flag_triangle;
    static const QString mdi_flag_variant;
    static const QString mdi_flag_variant_outline;
    static const QString mdi_flare;
    static const QString mdi_flash;
    static const QString mdi_flash_auto;
    static const QString mdi_flash_circle;
    static const QString mdi_flash_off;
    static const QString mdi_flash_outline;
    static const QString mdi_flash_red_eye;
    static const QString mdi_flashlight;
    static const QString mdi_flashlight_off;
    static const QString mdi_flask;
    static const QString mdi_flask_empty;
    static const QString mdi_flask_empty_outline;
    static const QString mdi_flask_outline;
    static const QString mdi_flattr;
    static const QString mdi_flickr;
    static const QString mdi_flip_to_back;
    static const QString mdi_flip_to_front;
    static const QString mdi_floor_lamp;
    static const QString mdi_floor_plan;
    static const QString mdi_floppy;
    static const QString mdi_floppy_variant;
    static const QString mdi_flower;
    static const QString mdi_flower_outline;
    static const QString mdi_flower_poppy;
    static const QString mdi_flower_tulip;
    static const QString mdi_flower_tulip_outline;
    static const QString mdi_folder;
    static const QString mdi_folder_account;
    static const QString mdi_folder_account_outline;
    static const QString mdi_folder_alert;
    static const QString mdi_folder_alert_outline;
    static const QString mdi_folder_clock;
    static const QString mdi_folder_clock_outline;
    static const QString mdi_folder_download;
    static const QString mdi_folder_edit;
    static const QString mdi_folder_edit_outline;
    static const QString mdi_folder_google_drive;
    static const QString mdi_folder_image;
    static const QString mdi_folder_key;
    static const QString mdi_folder_key_network;
    static const QString mdi_folder_key_network_outline;
    static const QString mdi_folder_lock;
    static const QString mdi_folder_lock_open;
    static const QString mdi_folder_move;
    static const QString mdi_folder_multiple;
    static const QString mdi_folder_multiple_image;
    static const QString mdi_folder_multiple_outline;
    static const QString mdi_folder_network;
    static const QString mdi_folder_network_outline;
    static const QString mdi_folder_open;
    static const QString mdi_folder_open_outline;
    static const QString mdi_folder_outline;
    static const QString mdi_folder_plus;
    static const QString mdi_folder_plus_outline;
    static const QString mdi_folder_pound;
    static const QString mdi_folder_pound_outline;
    static const QString mdi_folder_remove;
    static const QString mdi_folder_remove_outline;
    static const QString mdi_folder_search;
    static const QString mdi_folder_search_outline;
    static const QString mdi_folder_star;
    static const QString mdi_folder_star_outline;
    static const QString mdi_folder_sync;
    static const QString mdi_folder_sync_outline;
    static const QString mdi_folder_text;
    static const QString mdi_folder_text_outline;
    static const QString mdi_folder_upload;
    static const QString mdi_font_awesome;
    static const QString mdi_food;
    static const QString mdi_food_apple;
    static const QString mdi_food_apple_outline;
    static const QString mdi_food_croissant;
    static const QString mdi_food_fork_drink;
    static const QString mdi_food_off;
    static const QString mdi_food_variant;
    static const QString mdi_football;
    static const QString mdi_football_australian;
    static const QString mdi_football_helmet;
    static const QString mdi_forklift;
    static const QString mdi_format_align_bottom;
    static const QString mdi_format_align_center;
    static const QString mdi_format_align_justify;
    static const QString mdi_format_align_left;
    static const QString mdi_format_align_middle;
    static const QString mdi_format_align_right;
    static const QString mdi_format_align_top;
    static const QString mdi_format_annotation_minus;
    static const QString mdi_format_annotation_plus;
    static const QString mdi_format_bold;
    static const QString mdi_format_clear;
    static const QString mdi_format_color_fill;
    static const QString mdi_format_color_text;
    static const QString mdi_format_columns;
    static const QString mdi_format_float_center;
    static const QString mdi_format_float_left;
    static const QString mdi_format_float_none;
    static const QString mdi_format_float_right;
    static const QString mdi_format_font;
    static const QString mdi_format_font_size_decrease;
    static const QString mdi_format_font_size_increase;
    static const QString mdi_format_header_1;
    static const QString mdi_format_header_2;
    static const QString mdi_format_header_3;
    static const QString mdi_format_header_4;
    static const QString mdi_format_header_5;
    static const QString mdi_format_header_6;
    static const QString mdi_format_header_decrease;
    static const QString mdi_format_header_equal;
    static const QString mdi_format_header_increase;
    static const QString mdi_format_header_pound;
    static const QString mdi_format_horizontal_align_center;
    static const QString mdi_format_horizontal_align_left;
    static const QString mdi_format_horizontal_align_right;
    static const QString mdi_format_indent_decrease;
    static const QString mdi_format_indent_increase;
    static const QString mdi_format_italic;
    static const QString mdi_format_letter_case;
    static const QString mdi_format_letter_case_lower;
    static const QString mdi_format_letter_case_upper;
    static const QString mdi_format_line_spacing;
    static const QString mdi_format_line_style;
    static const QString mdi_format_line_weight;
    static const QString mdi_format_list_bulleted;
    static const QString mdi_format_list_bulleted_square;
    static const QString mdi_format_list_bulleted_type;
    static const QString mdi_format_list_checkbox;
    static const QString mdi_format_list_checks;
    static const QString mdi_format_list_numbered;
    static const QString mdi_format_list_numbered_rtl;
    static const QString mdi_format_page_break;
    static const QString mdi_format_paint;
    static const QString mdi_format_paragraph;
    static const QString mdi_format_pilcrow;
    static const QString mdi_format_quote_close;
    static const QString mdi_format_quote_open;
    static const QString mdi_format_rotate_90;
    static const QString mdi_format_section;
    static const QString mdi_format_size;
    static const QString mdi_format_strikethrough;
    static const QString mdi_format_strikethrough_variant;
    static const QString mdi_format_subscript;
    static const QString mdi_format_superscript;
    static const QString mdi_format_text;
    static const QString mdi_format_text_rotation_down;
    static const QString mdi_format_text_rotation_none;
    static const QString mdi_format_text_wrapping_clip;
    static const QString mdi_format_text_wrapping_overflow;
    static const QString mdi_format_text_wrapping_wrap;
    static const QString mdi_format_textbox;
    static const QString mdi_format_textdirection_l_to_r;
    static const QString mdi_format_textdirection_r_to_l;
    static const QString mdi_format_title;
    static const QString mdi_format_underline;
    static const QString mdi_format_vertical_align_bottom;
    static const QString mdi_format_vertical_align_center;
    static const QString mdi_format_vertical_align_top;
    static const QString mdi_format_wrap_inline;
    static const QString mdi_format_wrap_square;
    static const QString mdi_format_wrap_tight;
    static const QString mdi_format_wrap_top_bottom;
    static const QString mdi_forum;
    static const QString mdi_forum_outline;
    static const QString mdi_forward;
    static const QString mdi_forwardburger;
    static const QString mdi_fountain;
    static const QString mdi_fountain_pen;
    static const QString mdi_fountain_pen_tip;
    static const QString mdi_foursquare;
    static const QString mdi_freebsd;
    static const QString mdi_fridge;
    static const QString mdi_fridge_bottom;
    static const QString mdi_fridge_outline;
    static const QString mdi_fridge_top;
    static const QString mdi_fuel;
    static const QString mdi_fullscreen;
    static const QString mdi_fullscreen_exit;
    static const QString mdi_function;
    static const QString mdi_function_variant;
    static const QString mdi_fuse;
    static const QString mdi_fuse_blade;
    static const QString mdi_gamepad;
    static const QString mdi_gamepad_variant;
    static const QString mdi_gantry_crane;
    static const QString mdi_garage;
    static const QString mdi_garage_alert;
    static const QString mdi_garage_open;
    static const QString mdi_gas_cylinder;
    static const QString mdi_gas_station;
    static const QString mdi_gate;
    static const QString mdi_gate_and;
    static const QString mdi_gate_nand;
    static const QString mdi_gate_nor;
    static const QString mdi_gate_not;
    static const QString mdi_gate_or;
    static const QString mdi_gate_xnor;
    static const QString mdi_gate_xor;
    static const QString mdi_gauge;
    static const QString mdi_gauge_empty;
    static const QString mdi_gauge_full;
    static const QString mdi_gauge_low;
    static const QString mdi_gavel;
    static const QString mdi_gender_female;
    static const QString mdi_gender_male;
    static const QString mdi_gender_male_female;
    static const QString mdi_gender_transgender;
    static const QString mdi_gentoo;
    static const QString mdi_gesture;
    static const QString mdi_gesture_double_tap;
    static const QString mdi_gesture_pinch;
    static const QString mdi_gesture_spread;
    static const QString mdi_gesture_swipe;
    static const QString mdi_gesture_swipe_down;
    static const QString mdi_gesture_swipe_horizontal;
    static const QString mdi_gesture_swipe_left;
    static const QString mdi_gesture_swipe_right;
    static const QString mdi_gesture_swipe_up;
    static const QString mdi_gesture_swipe_vertical;
    static const QString mdi_gesture_tap;
    static const QString mdi_gesture_tap_hold;
    static const QString mdi_gesture_two_double_tap;
    static const QString mdi_gesture_two_tap;
    static const QString mdi_ghost;
    static const QString mdi_ghost_off;
    static const QString mdi_gif;
    static const QString mdi_gift;
    static const QString mdi_git;
    static const QString mdi_github_box;
    static const QString mdi_github_circle;
    static const QString mdi_github_face;
    static const QString mdi_gitlab;
    static const QString mdi_glass_cocktail;
    static const QString mdi_glass_flute;
    static const QString mdi_glass_mug;
    static const QString mdi_glass_stange;
    static const QString mdi_glass_tulip;
    static const QString mdi_glass_wine;
    static const QString mdi_glassdoor;
    static const QString mdi_glasses;
    static const QString mdi_globe_model;
    static const QString mdi_gmail;
    static const QString mdi_gnome;
    static const QString mdi_go_kart;
    static const QString mdi_go_kart_track;
    static const QString mdi_gog;
    static const QString mdi_golf;
    static const QString mdi_gondola;
    static const QString mdi_goodreads;
    static const QString mdi_google;
    static const QString mdi_google_adwords;
    static const QString mdi_google_allo;
    static const QString mdi_google_analytics;
    static const QString mdi_google_assistant;
    static const QString mdi_google_cardboard;
    static const QString mdi_google_chrome;
    static const QString mdi_google_circles;
    static const QString mdi_google_circles_communities;
    static const QString mdi_google_circles_extended;
    static const QString mdi_google_circles_group;
    static const QString mdi_google_classroom;
    static const QString mdi_google_controller;
    static const QString mdi_google_controller_off;
    static const QString mdi_google_drive;
    static const QString mdi_google_earth;
    static const QString mdi_google_fit;
    static const QString mdi_google_glass;
    static const QString mdi_google_hangouts;
    static const QString mdi_google_home;
    static const QString mdi_google_keep;
    static const QString mdi_google_lens;
    static const QString mdi_google_maps;
    static const QString mdi_google_nearby;
    static const QString mdi_google_pages;
    static const QString mdi_google_photos;
    static const QString mdi_google_physical_web;
    static const QString mdi_google_play;
    static const QString mdi_google_plus;
    static const QString mdi_google_plus_box;
    static const QString mdi_google_spreadsheet;
    static const QString mdi_google_street_view;
    static const QString mdi_google_translate;
    static const QString mdi_gpu;
    static const QString mdi_gradient;
    static const QString mdi_grain;
    static const QString mdi_graphql;
    static const QString mdi_grave_stone;
    static const QString mdi_grease_pencil;
    static const QString mdi_greater_than;
    static const QString mdi_greater_than_or_equal;
    static const QString mdi_grid;
    static const QString mdi_grid_large;
    static const QString mdi_grid_off;
    static const QString mdi_group;
    static const QString mdi_guitar_acoustic;
    static const QString mdi_guitar_electric;
    static const QString mdi_guitar_pick;
    static const QString mdi_guitar_pick_outline;
    static const QString mdi_guy_fawkes_mask;
    static const QString mdi_hackernews;
    static const QString mdi_hail;
    static const QString mdi_halloween;
    static const QString mdi_hamburger;
    static const QString mdi_hammer;
    static const QString mdi_hand;
    static const QString mdi_hand_okay;
    static const QString mdi_hand_peace;
    static const QString mdi_hand_peace_variant;
    static const QString mdi_hand_pointing_down;
    static const QString mdi_hand_pointing_left;
    static const QString mdi_hand_pointing_right;
    static const QString mdi_hand_pointing_up;
    static const QString mdi_hanger;
    static const QString mdi_hard_hat;
    static const QString mdi_harddisk;
    static const QString mdi_hat_fedora;
    static const QString mdi_hazard_lights;
    static const QString mdi_hdr;
    static const QString mdi_hdr_off;
    static const QString mdi_headphones;
    static const QString mdi_headphones_bluetooth;
    static const QString mdi_headphones_box;
    static const QString mdi_headphones_off;
    static const QString mdi_headphones_settings;
    static const QString mdi_headset;
    static const QString mdi_headset_dock;
    static const QString mdi_headset_off;
    static const QString mdi_heart;
    static const QString mdi_heart_box;
    static const QString mdi_heart_box_outline;
    static const QString mdi_heart_broken;
    static const QString mdi_heart_broken_outline;
    static const QString mdi_heart_circle;
    static const QString mdi_heart_circle_outline;
    static const QString mdi_heart_half;
    static const QString mdi_heart_half_full;
    static const QString mdi_heart_half_outline;
    static const QString mdi_heart_multiple;
    static const QString mdi_heart_multiple_outline;
    static const QString mdi_heart_off;
    static const QString mdi_heart_outline;
    static const QString mdi_heart_pulse;
    static const QString mdi_helicopter;
    static const QString mdi_help;
    static const QString mdi_help_box;
    static const QString mdi_help_circle;
    static const QString mdi_help_circle_outline;
    static const QString mdi_help_network;
    static const QString mdi_help_network_outline;
    static const QString mdi_help_rhombus;
    static const QString mdi_help_rhombus_outline;
    static const QString mdi_hexagon;
    static const QString mdi_hexagon_multiple;
    static const QString mdi_hexagon_outline;
    static const QString mdi_hexagon_slice_1;
    static const QString mdi_hexagon_slice_2;
    static const QString mdi_hexagon_slice_3;
    static const QString mdi_hexagon_slice_4;
    static const QString mdi_hexagon_slice_5;
    static const QString mdi_hexagon_slice_6;
    static const QString mdi_hexagram;
    static const QString mdi_hexagram_outline;
    static const QString mdi_high_definition;
    static const QString mdi_high_definition_box;
    static const QString mdi_highway;
    static const QString mdi_hiking;
    static const QString mdi_hinduism;
    static const QString mdi_history;
    static const QString mdi_hockey_puck;
    static const QString mdi_hockey_sticks;
    static const QString mdi_hololens;
    static const QString mdi_home;
    static const QString mdi_home_account;
    static const QString mdi_home_alert;
    static const QString mdi_home_assistant;
    static const QString mdi_home_automation;
    static const QString mdi_home_circle;
    static const QString mdi_home_city;
    static const QString mdi_home_city_outline;
    static const QString mdi_home_currency_usd;
    static const QString mdi_home_floor_0;
    static const QString mdi_home_floor_1;
    static const QString mdi_home_floor_2;
    static const QString mdi_home_floor_3;
    static const QString mdi_home_floor_a;
    static const QString mdi_home_floor_b;
    static const QString mdi_home_floor_g;
    static const QString mdi_home_floor_l;
    static const QString mdi_home_floor_negative_1;
    static const QString mdi_home_group;
    static const QString mdi_home_heart;
    static const QString mdi_home_lock;
    static const QString mdi_home_lock_open;
    static const QString mdi_home_map_marker;
    static const QString mdi_home_minus;
    static const QString mdi_home_modern;
    static const QString mdi_home_outline;
    static const QString mdi_home_plus;
    static const QString mdi_home_variant;
    static const QString mdi_home_variant_outline;
    static const QString mdi_hook;
    static const QString mdi_hook_off;
    static const QString mdi_hops;
    static const QString mdi_horseshoe;
    static const QString mdi_hospital;
    static const QString mdi_hospital_building;
    static const QString mdi_hospital_marker;
    static const QString mdi_hot_tub;
    static const QString mdi_hotel;
    static const QString mdi_houzz;
    static const QString mdi_houzz_box;
    static const QString mdi_hubspot;
    static const QString mdi_hulu;
    static const QString mdi_human;
    static const QString mdi_human_child;
    static const QString mdi_human_female;
    static const QString mdi_human_female_boy;
    static const QString mdi_human_female_female;
    static const QString mdi_human_female_girl;
    static const QString mdi_human_greeting;
    static const QString mdi_human_handsdown;
    static const QString mdi_human_handsup;
    static const QString mdi_human_male;
    static const QString mdi_human_male_boy;
    static const QString mdi_human_male_female;
    static const QString mdi_human_male_girl;
    static const QString mdi_human_male_male;
    static const QString mdi_human_pregnant;
    static const QString mdi_humble_bundle;
    static const QString mdi_ice_cream;
    static const QString mdi_iframe;
    static const QString mdi_iframe_outline;
    static const QString mdi_image;
    static const QString mdi_image_album;
    static const QString mdi_image_area;
    static const QString mdi_image_area_close;
    static const QString mdi_image_broken;
    static const QString mdi_image_broken_variant;
    static const QString mdi_image_filter;
    static const QString mdi_image_filter_black_white;
    static const QString mdi_image_filter_center_focus;
    static const QString mdi_image_filter_center_focus_weak;
    static const QString mdi_image_filter_drama;
    static const QString mdi_image_filter_frames;
    static const QString mdi_image_filter_hdr;
    static const QString mdi_image_filter_none;
    static const QString mdi_image_filter_tilt_shift;
    static const QString mdi_image_filter_vintage;
    static const QString mdi_image_move;
    static const QString mdi_image_multiple;
    static const QString mdi_image_off;
    static const QString mdi_image_outline;
    static const QString mdi_image_plus;
    static const QString mdi_image_search;
    static const QString mdi_image_search_outline;
    static const QString mdi_image_size_select_actual;
    static const QString mdi_image_size_select_large;
    static const QString mdi_image_size_select_small;
    static const QString mdi_import;
    static const QString mdi_inbox;
    static const QString mdi_inbox_arrow_down;
    static const QString mdi_inbox_arrow_up;
    static const QString mdi_inbox_multiple;
    static const QString mdi_inbox_multiple_outline;
    static const QString mdi_incognito;
    static const QString mdi_infinity;
    static const QString mdi_information;
    static const QString mdi_information_outline;
    static const QString mdi_information_variant;
    static const QString mdi_instagram;
    static const QString mdi_instapaper;
    static const QString mdi_internet_explorer;
    static const QString mdi_invert_colors;
    static const QString mdi_ip;
    static const QString mdi_ip_network;
    static const QString mdi_ip_network_outline;
    static const QString mdi_ipod;
    static const QString mdi_islam;
    static const QString mdi_itunes;
    static const QString mdi_jabber;
    static const QString mdi_jeepney;
    static const QString mdi_jira;
    static const QString mdi_jquery;
    static const QString mdi_jsfiddle;
    static const QString mdi_json;
    static const QString mdi_judaism;
    static const QString mdi_kabaddi;
    static const QString mdi_karate;
    static const QString mdi_keg;
    static const QString mdi_kettle;
    static const QString mdi_key;
    static const QString mdi_key_change;
    static const QString mdi_key_minus;
    static const QString mdi_key_outline;
    static const QString mdi_key_plus;
    static const QString mdi_key_remove;
    static const QString mdi_key_variant;
    static const QString mdi_keyboard;
    static const QString mdi_keyboard_backspace;
    static const QString mdi_keyboard_caps;
    static const QString mdi_keyboard_close;
    static const QString mdi_keyboard_off;
    static const QString mdi_keyboard_outline;
    static const QString mdi_keyboard_return;
    static const QString mdi_keyboard_settings;
    static const QString mdi_keyboard_settings_outline;
    static const QString mdi_keyboard_tab;
    static const QString mdi_keyboard_variant;
    static const QString mdi_kickstarter;
    static const QString mdi_knife;
    static const QString mdi_knife_military;
    static const QString mdi_kodi;
    static const QString mdi_label;
    static const QString mdi_label_off;
    static const QString mdi_label_off_outline;
    static const QString mdi_label_outline;
    static const QString mdi_label_variant;
    static const QString mdi_label_variant_outline;
    static const QString mdi_ladybug;
    static const QString mdi_lambda;
    static const QString mdi_lamp;
    static const QString mdi_lan;
    static const QString mdi_lan_connect;
    static const QString mdi_lan_disconnect;
    static const QString mdi_lan_pending;
    static const QString mdi_language_c;
    static const QString mdi_language_cpp;
    static const QString mdi_language_csharp;
    static const QString mdi_language_css3;
    static const QString mdi_language_go;
    static const QString mdi_language_haskell;
    static const QString mdi_language_html5;
    static const QString mdi_language_java;
    static const QString mdi_language_javascript;
    static const QString mdi_language_lua;
    static const QString mdi_language_php;
    static const QString mdi_language_python;
    static const QString mdi_language_python_text;
    static const QString mdi_language_r;
    static const QString mdi_language_ruby_on_rails;
    static const QString mdi_language_swift;
    static const QString mdi_language_typescript;
    static const QString mdi_laptop;
    static const QString mdi_laptop_chromebook;
    static const QString mdi_laptop_mac;
    static const QString mdi_laptop_off;
    static const QString mdi_laptop_windows;
    static const QString mdi_laravel;
    static const QString mdi_lastfm;
    static const QString mdi_lastpass;
    static const QString mdi_launch;
    static const QString mdi_lava_lamp;
    static const QString mdi_layers;
    static const QString mdi_layers_off;
    static const QString mdi_layers_off_outline;
    static const QString mdi_layers_outline;
    static const QString mdi_lead_pencil;
    static const QString mdi_leaf;
    static const QString mdi_leaf_maple;
    static const QString mdi_leak;
    static const QString mdi_leak_off;
    static const QString mdi_led_off;
    static const QString mdi_led_on;
    static const QString mdi_led_outline;
    static const QString mdi_led_strip;
    static const QString mdi_led_variant_off;
    static const QString mdi_led_variant_on;
    static const QString mdi_led_variant_outline;
    static const QString mdi_less_than;
    static const QString mdi_less_than_or_equal;
    static const QString mdi_library;
    static const QString mdi_library_books;
    static const QString mdi_library_movie;
    static const QString mdi_library_music;
    static const QString mdi_library_plus;
    static const QString mdi_library_shelves;
    static const QString mdi_library_video;
    static const QString mdi_lifebuoy;
    static const QString mdi_light_switch;
    static const QString mdi_lightbulb;
    static const QString mdi_lightbulb_on;
    static const QString mdi_lightbulb_on_outline;
    static const QString mdi_lightbulb_outline;
    static const QString mdi_lighthouse;
    static const QString mdi_lighthouse_on;
    static const QString mdi_link;
    static const QString mdi_link_box;
    static const QString mdi_link_box_outline;
    static const QString mdi_link_box_variant;
    static const QString mdi_link_box_variant_outline;
    static const QString mdi_link_off;
    static const QString mdi_link_plus;
    static const QString mdi_link_variant;
    static const QString mdi_link_variant_off;
    static const QString mdi_linkedin;
    static const QString mdi_linkedin_box;
    static const QString mdi_linux;
    static const QString mdi_linux_mint;
    static const QString mdi_litecoin;
    static const QString mdi_loading;
    static const QString mdi_lock;
    static const QString mdi_lock_alert;
    static const QString mdi_lock_clock;
    static const QString mdi_lock_open;
    static const QString mdi_lock_open_outline;
    static const QString mdi_lock_outline;
    static const QString mdi_lock_pattern;
    static const QString mdi_lock_plus;
    static const QString mdi_lock_question;
    static const QString mdi_lock_reset;
    static const QString mdi_lock_smart;
    static const QString mdi_locker;
    static const QString mdi_locker_multiple;
    static const QString mdi_login;
    static const QString mdi_login_variant;
    static const QString mdi_logout;
    static const QString mdi_logout_variant;
    static const QString mdi_looks;
    static const QString mdi_loop;
    static const QString mdi_loupe;
    static const QString mdi_lumx;
    static const QString mdi_lyft;
    static const QString mdi_magnet;
    static const QString mdi_magnet_on;
    static const QString mdi_magnify;
    static const QString mdi_magnify_close;
    static const QString mdi_magnify_minus;
    static const QString mdi_magnify_minus_cursor;
    static const QString mdi_magnify_minus_outline;
    static const QString mdi_magnify_plus;
    static const QString mdi_magnify_plus_cursor;
    static const QString mdi_magnify_plus_outline;
    static const QString mdi_mail_ru;
    static const QString mdi_mailbox;
    static const QString mdi_mailbox_open;
    static const QString mdi_mailbox_open_outline;
    static const QString mdi_mailbox_open_up;
    static const QString mdi_mailbox_open_up_outline;
    static const QString mdi_mailbox_outline;
    static const QString mdi_mailbox_up;
    static const QString mdi_mailbox_up_outline;
    static const QString mdi_map;
    static const QString mdi_map_clock;
    static const QString mdi_map_clock_outline;
    static const QString mdi_map_legend;
    static const QString mdi_map_marker;
    static const QString mdi_map_marker_check;
    static const QString mdi_map_marker_circle;
    static const QString mdi_map_marker_distance;
    static const QString mdi_map_marker_minus;
    static const QString mdi_map_marker_multiple;
    static const QString mdi_map_marker_off;
    static const QString mdi_map_marker_outline;
    static const QString mdi_map_marker_path;
    static const QString mdi_map_marker_plus;
    static const QString mdi_map_marker_radius;
    static const QString mdi_map_minus;
    static const QString mdi_map_outline;
    static const QString mdi_map_plus;
    static const QString mdi_map_search;
    static const QString mdi_map_search_outline;
    static const QString mdi_mapbox;
    static const QString mdi_margin;
    static const QString mdi_markdown;
    static const QString mdi_marker;
    static const QString mdi_marker_cancel;
    static const QString mdi_marker_check;
    static const QString mdi_mastodon;
    static const QString mdi_mastodon_variant;
    static const QString mdi_material_design;
    static const QString mdi_material_ui;
    static const QString mdi_math_compass;
    static const QString mdi_math_cos;
    static const QString mdi_math_sin;
    static const QString mdi_math_tan;
    static const QString mdi_matrix;
    static const QString mdi_maxcdn;
    static const QString mdi_medal;
    static const QString mdi_medical_bag;
    static const QString mdi_medium;
    static const QString mdi_meetup;
    static const QString mdi_memory;
    static const QString mdi_menu;
    static const QString mdi_menu_down;
    static const QString mdi_menu_down_outline;
    static const QString mdi_menu_left;
    static const QString mdi_menu_left_outline;
    static const QString mdi_menu_open;
    static const QString mdi_menu_right;
    static const QString mdi_menu_right_outline;
    static const QString mdi_menu_swap;
    static const QString mdi_menu_swap_outline;
    static const QString mdi_menu_up;
    static const QString mdi_menu_up_outline;
    static const QString mdi_message;
    static const QString mdi_message_alert;
    static const QString mdi_message_alert_outline;
    static const QString mdi_message_bulleted;
    static const QString mdi_message_bulleted_off;
    static const QString mdi_message_draw;
    static const QString mdi_message_image;
    static const QString mdi_message_outline;
    static const QString mdi_message_plus;
    static const QString mdi_message_processing;
    static const QString mdi_message_reply;
    static const QString mdi_message_reply_text;
    static const QString mdi_message_settings;
    static const QString mdi_message_settings_variant;
    static const QString mdi_message_text;
    static const QString mdi_message_text_outline;
    static const QString mdi_message_video;
    static const QString mdi_meteor;
    static const QString mdi_metronome;
    static const QString mdi_metronome_tick;
    static const QString mdi_micro_sd;
    static const QString mdi_microphone;
    static const QString mdi_microphone_minus;
    static const QString mdi_microphone_off;
    static const QString mdi_microphone_outline;
    static const QString mdi_microphone_plus;
    static const QString mdi_microphone_settings;
    static const QString mdi_microphone_variant;
    static const QString mdi_microphone_variant_off;
    static const QString mdi_microscope;
    static const QString mdi_microsoft;
    static const QString mdi_microsoft_dynamics;
    static const QString mdi_microwave;
    static const QString mdi_midi;
    static const QString mdi_midi_port;
    static const QString mdi_mine;
    static const QString mdi_minecraft;
    static const QString mdi_mini_sd;
    static const QString mdi_minidisc;
    static const QString mdi_minus;
    static const QString mdi_minus_box;
    static const QString mdi_minus_box_outline;
    static const QString mdi_minus_circle;
    static const QString mdi_minus_circle_outline;
    static const QString mdi_minus_network;
    static const QString mdi_minus_network_outline;
    static const QString mdi_mixcloud;
    static const QString mdi_mixed_martial_arts;
    static const QString mdi_mixed_reality;
    static const QString mdi_mixer;
    static const QString mdi_molecule;
    static const QString mdi_monitor;
    static const QString mdi_monitor_cellphone;
    static const QString mdi_monitor_cellphone_star;
    static const QString mdi_monitor_dashboard;
    static const QString mdi_monitor_lock;
    static const QString mdi_monitor_multiple;
    static const QString mdi_monitor_off;
    static const QString mdi_monitor_star;
    static const QString mdi_more;
    static const QString mdi_mother_nurse;
    static const QString mdi_motion_sensor;
    static const QString mdi_motorbike;
    static const QString mdi_mouse;
    static const QString mdi_mouse_bluetooth;
    static const QString mdi_mouse_off;
    static const QString mdi_mouse_variant;
    static const QString mdi_mouse_variant_off;
    static const QString mdi_move_resize;
    static const QString mdi_move_resize_variant;
    static const QString mdi_movie;
    static const QString mdi_movie_outline;
    static const QString mdi_movie_roll;
    static const QString mdi_muffin;
    static const QString mdi_multiplication;
    static const QString mdi_multiplication_box;
    static const QString mdi_mushroom;
    static const QString mdi_mushroom_outline;
    static const QString mdi_music;
    static const QString mdi_music_box;
    static const QString mdi_music_box_outline;
    static const QString mdi_music_circle;
    static const QString mdi_music_circle_outline;
    static const QString mdi_music_note;
    static const QString mdi_music_note_bluetooth;
    static const QString mdi_music_note_bluetooth_off;
    static const QString mdi_music_note_eighth;
    static const QString mdi_music_note_half;
    static const QString mdi_music_note_off;
    static const QString mdi_music_note_plus;
    static const QString mdi_music_note_quarter;
    static const QString mdi_music_note_sixteenth;
    static const QString mdi_music_note_whole;
    static const QString mdi_music_off;
    static const QString mdi_nail;
    static const QString mdi_nas;
    static const QString mdi_nativescript;
    static const QString mdi_nature;
    static const QString mdi_nature_people;
    static const QString mdi_navigation;
    static const QString mdi_near_me;
    static const QString mdi_needle;
    static const QString mdi_netflix;
    static const QString mdi_network;
    static const QString mdi_network_off;
    static const QString mdi_network_off_outline;
    static const QString mdi_network_outline;
    static const QString mdi_network_strength_1;
    static const QString mdi_network_strength_1_alert;
    static const QString mdi_network_strength_2;
    static const QString mdi_network_strength_2_alert;
    static const QString mdi_network_strength_3;
    static const QString mdi_network_strength_3_alert;
    static const QString mdi_network_strength_4;
    static const QString mdi_network_strength_4_alert;
    static const QString mdi_network_strength_off;
    static const QString mdi_network_strength_off_outline;
    static const QString mdi_network_strength_outline;
    static const QString mdi_new_box;
    static const QString mdi_newspaper;
    static const QString mdi_nfc;
    static const QString mdi_nfc_tap;
    static const QString mdi_nfc_variant;
    static const QString mdi_ninja;
    static const QString mdi_nintendo_switch;
    static const QString mdi_nodejs;
    static const QString mdi_not_equal;
    static const QString mdi_not_equal_variant;
    static const QString mdi_note;
    static const QString mdi_note_multiple;
    static const QString mdi_note_multiple_outline;
    static const QString mdi_note_outline;
    static const QString mdi_note_plus;
    static const QString mdi_note_plus_outline;
    static const QString mdi_note_text;
    static const QString mdi_notebook;
    static const QString mdi_notification_clear_all;
    static const QString mdi_npm;
    static const QString mdi_npm_variant;
    static const QString mdi_npm_variant_outline;
    static const QString mdi_nuke;
    static const QString mdi_null;
    static const QString mdi_numeric;
    static const QString mdi_numeric_0;
    static const QString mdi_numeric_0_box;
    static const QString mdi_numeric_0_box_multiple_outline;
    static const QString mdi_numeric_0_box_outline;
    static const QString mdi_numeric_0_circle;
    static const QString mdi_numeric_0_circle_outline;
    static const QString mdi_numeric_1;
    static const QString mdi_numeric_1_box;
    static const QString mdi_numeric_1_box_multiple_outline;
    static const QString mdi_numeric_1_box_outline;
    static const QString mdi_numeric_1_circle;
    static const QString mdi_numeric_1_circle_outline;
    static const QString mdi_numeric_2;
    static const QString mdi_numeric_2_box;
    static const QString mdi_numeric_2_box_multiple_outline;
    static const QString mdi_numeric_2_box_outline;
    static const QString mdi_numeric_2_circle;
    static const QString mdi_numeric_2_circle_outline;
    static const QString mdi_numeric_3;
    static const QString mdi_numeric_3_box;
    static const QString mdi_numeric_3_box_multiple_outline;
    static const QString mdi_numeric_3_box_outline;
    static const QString mdi_numeric_3_circle;
    static const QString mdi_numeric_3_circle_outline;
    static const QString mdi_numeric_4;
    static const QString mdi_numeric_4_box;
    static const QString mdi_numeric_4_box_multiple_outline;
    static const QString mdi_numeric_4_box_outline;
    static const QString mdi_numeric_4_circle;
    static const QString mdi_numeric_4_circle_outline;
    static const QString mdi_numeric_5;
    static const QString mdi_numeric_5_box;
    static const QString mdi_numeric_5_box_multiple_outline;
    static const QString mdi_numeric_5_box_outline;
    static const QString mdi_numeric_5_circle;
    static const QString mdi_numeric_5_circle_outline;
    static const QString mdi_numeric_6;
    static const QString mdi_numeric_6_box;
    static const QString mdi_numeric_6_box_multiple_outline;
    static const QString mdi_numeric_6_box_outline;
    static const QString mdi_numeric_6_circle;
    static const QString mdi_numeric_6_circle_outline;
    static const QString mdi_numeric_7;
    static const QString mdi_numeric_7_box;
    static const QString mdi_numeric_7_box_multiple_outline;
    static const QString mdi_numeric_7_box_outline;
    static const QString mdi_numeric_7_circle;
    static const QString mdi_numeric_7_circle_outline;
    static const QString mdi_numeric_8;
    static const QString mdi_numeric_8_box;
    static const QString mdi_numeric_8_box_multiple_outline;
    static const QString mdi_numeric_8_box_outline;
    static const QString mdi_numeric_8_circle;
    static const QString mdi_numeric_8_circle_outline;
    static const QString mdi_numeric_9;
    static const QString mdi_numeric_9_box;
    static const QString mdi_numeric_9_box_multiple_outline;
    static const QString mdi_numeric_9_box_outline;
    static const QString mdi_numeric_9_circle;
    static const QString mdi_numeric_9_circle_outline;
    static const QString mdi_numeric_9_plus_box;
    static const QString mdi_numeric_9_plus_box_multiple_outline;
    static const QString mdi_numeric_9_plus_box_outline;
    static const QString mdi_numeric_9_plus_circle;
    static const QString mdi_numeric_9_plus_circle_outline;
    static const QString mdi_nut;
    static const QString mdi_nutrition;
    static const QString mdi_oar;
    static const QString mdi_ocarina;
    static const QString mdi_octagon;
    static const QString mdi_octagon_outline;
    static const QString mdi_octagram;
    static const QString mdi_octagram_outline;
    static const QString mdi_odnoklassniki;
    static const QString mdi_office;
    static const QString mdi_office_building;
    static const QString mdi_oil;
    static const QString mdi_oil_temperature;
    static const QString mdi_omega;
    static const QString mdi_one_up;
    static const QString mdi_onedrive;
    static const QString mdi_onenote;
    static const QString mdi_onepassword;
    static const QString mdi_opacity;
    static const QString mdi_open_in_app;
    static const QString mdi_open_in_new;
    static const QString mdi_open_source_initiative;
    static const QString mdi_openid;
    static const QString mdi_opera;
    static const QString mdi_orbit;
    static const QString mdi_origin;
    static const QString mdi_ornament;
    static const QString mdi_ornament_variant;
    static const QString mdi_outlook;
    static const QString mdi_owl;
    static const QString mdi_pac_man;
    static const QString mdi_package;
    static const QString mdi_package_down;
    static const QString mdi_package_up;
    static const QString mdi_package_variant;
    static const QString mdi_package_variant_closed;
    static const QString mdi_page_first;
    static const QString mdi_page_last;
    static const QString mdi_page_layout_body;
    static const QString mdi_page_layout_footer;
    static const QString mdi_page_layout_header;
    static const QString mdi_page_layout_sidebar_left;
    static const QString mdi_page_layout_sidebar_right;
    static const QString mdi_page_next;
    static const QString mdi_page_next_outline;
    static const QString mdi_page_previous;
    static const QString mdi_page_previous_outline;
    static const QString mdi_palette;
    static const QString mdi_palette_advanced;
    static const QString mdi_palette_swatch;
    static const QString mdi_pan;
    static const QString mdi_pan_bottom_left;
    static const QString mdi_pan_bottom_right;
    static const QString mdi_pan_down;
    static const QString mdi_pan_horizontal;
    static const QString mdi_pan_left;
    static const QString mdi_pan_right;
    static const QString mdi_pan_top_left;
    static const QString mdi_pan_top_right;
    static const QString mdi_pan_up;
    static const QString mdi_pan_vertical;
    static const QString mdi_panda;
    static const QString mdi_pandora;
    static const QString mdi_panorama;
    static const QString mdi_panorama_fisheye;
    static const QString mdi_panorama_horizontal;
    static const QString mdi_panorama_vertical;
    static const QString mdi_panorama_wide_angle;
    static const QString mdi_paper_cut_vertical;
    static const QString mdi_paperclip;
    static const QString mdi_parachute;
    static const QString mdi_parachute_outline;
    static const QString mdi_parking;
    static const QString mdi_passport;
    static const QString mdi_passport_biometric;
    static const QString mdi_patreon;
    static const QString mdi_pause;
    static const QString mdi_pause_circle;
    static const QString mdi_pause_circle_outline;
    static const QString mdi_pause_octagon;
    static const QString mdi_pause_octagon_outline;
    static const QString mdi_paw;
    static const QString mdi_paw_off;
    static const QString mdi_paypal;
    static const QString mdi_peace;
    static const QString mdi_pen;
    static const QString mdi_pen_lock;
    static const QString mdi_pen_minus;
    static const QString mdi_pen_off;
    static const QString mdi_pen_plus;
    static const QString mdi_pen_remove;
    static const QString mdi_pencil;
    static const QString mdi_pencil_box;
    static const QString mdi_pencil_box_outline;
    static const QString mdi_pencil_circle;
    static const QString mdi_pencil_circle_outline;
    static const QString mdi_pencil_lock;
    static const QString mdi_pencil_lock_outline;
    static const QString mdi_pencil_minus;
    static const QString mdi_pencil_minus_outline;
    static const QString mdi_pencil_off;
    static const QString mdi_pencil_off_outline;
    static const QString mdi_pencil_outline;
    static const QString mdi_pencil_plus;
    static const QString mdi_pencil_plus_outline;
    static const QString mdi_pencil_remove;
    static const QString mdi_pencil_remove_outline;
    static const QString mdi_pentagon;
    static const QString mdi_pentagon_outline;
    static const QString mdi_percent;
    static const QString mdi_periodic_table;
    static const QString mdi_periodic_table_co2;
    static const QString mdi_periscope;
    static const QString mdi_perspective_less;
    static const QString mdi_perspective_more;
    static const QString mdi_pharmacy;
    static const QString mdi_phone;
    static const QString mdi_phone_bluetooth;
    static const QString mdi_phone_classic;
    static const QString mdi_phone_forward;
    static const QString mdi_phone_hangup;
    static const QString mdi_phone_in_talk;
    static const QString mdi_phone_incoming;
    static const QString mdi_phone_lock;
    static const QString mdi_phone_log;
    static const QString mdi_phone_minus;
    static const QString mdi_phone_missed;
    static const QString mdi_phone_off;
    static const QString mdi_phone_outgoing;
    static const QString mdi_phone_outline;
    static const QString mdi_phone_paused;
    static const QString mdi_phone_plus;
    static const QString mdi_phone_return;
    static const QString mdi_phone_rotate_landscape;
    static const QString mdi_phone_rotate_portrait;
    static const QString mdi_phone_settings;
    static const QString mdi_phone_voip;
    static const QString mdi_pi;
    static const QString mdi_pi_box;
    static const QString mdi_pi_hole;
    static const QString mdi_piano;
    static const QString mdi_pickaxe;
    static const QString mdi_pier;
    static const QString mdi_pier_crane;
    static const QString mdi_pig;
    static const QString mdi_pill;
    static const QString mdi_pillar;
    static const QString mdi_pin;
    static const QString mdi_pin_off;
    static const QString mdi_pin_off_outline;
    static const QString mdi_pin_outline;
    static const QString mdi_pine_tree;
    static const QString mdi_pine_tree_box;
    static const QString mdi_pinterest;
    static const QString mdi_pinterest_box;
    static const QString mdi_pinwheel;
    static const QString mdi_pinwheel_outline;
    static const QString mdi_pipe;
    static const QString mdi_pipe_disconnected;
    static const QString mdi_pipe_leak;
    static const QString mdi_pirate;
    static const QString mdi_pistol;
    static const QString mdi_piston;
    static const QString mdi_pizza;
    static const QString mdi_play;
    static const QString mdi_play_box_outline;
    static const QString mdi_play_circle;
    static const QString mdi_play_circle_outline;
    static const QString mdi_play_network;
    static const QString mdi_play_network_outline;
    static const QString mdi_play_pause;
    static const QString mdi_play_protected_content;
    static const QString mdi_play_speed;
    static const QString mdi_playlist_check;
    static const QString mdi_playlist_edit;
    static const QString mdi_playlist_minus;
    static const QString mdi_playlist_music;
    static const QString mdi_playlist_music_outline;
    static const QString mdi_playlist_play;
    static const QString mdi_playlist_plus;
    static const QString mdi_playlist_remove;
    static const QString mdi_playlist_star;
    static const QString mdi_playstation;
    static const QString mdi_plex;
    static const QString mdi_plus;
    static const QString mdi_plus_box;
    static const QString mdi_plus_box_outline;
    static const QString mdi_plus_circle;
    static const QString mdi_plus_circle_multiple_outline;
    static const QString mdi_plus_circle_outline;
    static const QString mdi_plus_minus;
    static const QString mdi_plus_minus_box;
    static const QString mdi_plus_network;
    static const QString mdi_plus_network_outline;
    static const QString mdi_plus_one;
    static const QString mdi_plus_outline;
    static const QString mdi_pocket;
    static const QString mdi_podcast;
    static const QString mdi_podium;
    static const QString mdi_podium_bronze;
    static const QString mdi_podium_gold;
    static const QString mdi_podium_silver;
    static const QString mdi_point_of_sale;
    static const QString mdi_pokeball;
    static const QString mdi_pokemon_go;
    static const QString mdi_poker_chip;
    static const QString mdi_polaroid;
    static const QString mdi_poll;
    static const QString mdi_poll_box;
    static const QString mdi_polymer;
    static const QString mdi_pool;
    static const QString mdi_popcorn;
    static const QString mdi_postage_stamp;
    static const QString mdi_pot;
    static const QString mdi_pot_mix;
    static const QString mdi_pound;
    static const QString mdi_pound_box;
    static const QString mdi_power;
    static const QString mdi_power_cycle;
    static const QString mdi_power_off;
    static const QString mdi_power_on;
    static const QString mdi_power_plug;
    static const QString mdi_power_plug_off;
    static const QString mdi_power_settings;
    static const QString mdi_power_sleep;
    static const QString mdi_power_socket;
    static const QString mdi_power_socket_au;
    static const QString mdi_power_socket_eu;
    static const QString mdi_power_socket_uk;
    static const QString mdi_power_socket_us;
    static const QString mdi_power_standby;
    static const QString mdi_powershell;
    static const QString mdi_prescription;
    static const QString mdi_presentation;
    static const QString mdi_presentation_play;
    static const QString mdi_printer;
    static const QString mdi_printer_3d;
    static const QString mdi_printer_alert;
    static const QString mdi_printer_settings;
    static const QString mdi_printer_wireless;
    static const QString mdi_priority_high;
    static const QString mdi_priority_low;
    static const QString mdi_professional_hexagon;
    static const QString mdi_progress_alert;
    static const QString mdi_progress_check;
    static const QString mdi_progress_clock;
    static const QString mdi_progress_download;
    static const QString mdi_progress_upload;
    static const QString mdi_progress_wrench;
    static const QString mdi_projector;
    static const QString mdi_projector_screen;
    static const QString mdi_publish;
    static const QString mdi_pulse;
    static const QString mdi_pumpkin;
    static const QString mdi_puzzle;
    static const QString mdi_puzzle_outline;
    static const QString mdi_qi;
    static const QString mdi_qqchat;
    static const QString mdi_qrcode;
    static const QString mdi_qrcode_edit;
    static const QString mdi_qrcode_scan;
    static const QString mdi_quadcopter;
    static const QString mdi_quality_high;
    static const QString mdi_quality_low;
    static const QString mdi_quality_medium;
    static const QString mdi_quicktime;
    static const QString mdi_quora;
    static const QString mdi_rabbit;
    static const QString mdi_racing_helmet;
    static const QString mdi_racquetball;
    static const QString mdi_radar;
    static const QString mdi_radiator;
    static const QString mdi_radiator_disabled;
    static const QString mdi_radiator_off;
    static const QString mdi_radio;
    static const QString mdi_radio_am;
    static const QString mdi_radio_fm;
    static const QString mdi_radio_handheld;
    static const QString mdi_radio_tower;
    static const QString mdi_radioactive;
    static const QString mdi_radiobox_blank;
    static const QString mdi_radiobox_marked;
    static const QString mdi_radius;
    static const QString mdi_radius_outline;
    static const QString mdi_raspberry_pi;
    static const QString mdi_ray_end;
    static const QString mdi_ray_end_arrow;
    static const QString mdi_ray_start;
    static const QString mdi_ray_start_arrow;
    static const QString mdi_ray_start_end;
    static const QString mdi_ray_vertex;
    static const QString mdi_react;
    static const QString mdi_read;
    static const QString mdi_receipt;
    static const QString mdi_record;
    static const QString mdi_record_player;
    static const QString mdi_record_rec;
    static const QString mdi_recycle;
    static const QString mdi_reddit;
    static const QString mdi_redo;
    static const QString mdi_redo_variant;
    static const QString mdi_reflect_horizontal;
    static const QString mdi_reflect_vertical;
    static const QString mdi_refresh;
    static const QString mdi_regex;
    static const QString mdi_registered_trademark;
    static const QString mdi_relative_scale;
    static const QString mdi_reload;
    static const QString mdi_reminder;
    static const QString mdi_remote;
    static const QString mdi_remote_desktop;
    static const QString mdi_rename_box;
    static const QString mdi_reorder_horizontal;
    static const QString mdi_reorder_vertical;
    static const QString mdi_repeat;
    static const QString mdi_repeat_off;
    static const QString mdi_repeat_once;
    static const QString mdi_replay;
    static const QString mdi_reply;
    static const QString mdi_reply_all;
    static const QString mdi_reproduction;
    static const QString mdi_resistor;
    static const QString mdi_resistor_nodes;
    static const QString mdi_resize;
    static const QString mdi_resize_bottom_right;
    static const QString mdi_responsive;
    static const QString mdi_restart;
    static const QString mdi_restart_off;
    static const QString mdi_restore;
    static const QString mdi_restore_clock;
    static const QString mdi_rewind;
    static const QString mdi_rewind_10;
    static const QString mdi_rewind_30;
    static const QString mdi_rewind_outline;
    static const QString mdi_rhombus;
    static const QString mdi_rhombus_medium;
    static const QString mdi_rhombus_outline;
    static const QString mdi_rhombus_split;
    static const QString mdi_ribbon;
    static const QString mdi_rice;
    static const QString mdi_ring;
    static const QString mdi_road;
    static const QString mdi_road_variant;
    static const QString mdi_robot;
    static const QString mdi_robot_industrial;
    static const QString mdi_robot_vacuum;
    static const QString mdi_robot_vacuum_variant;
    static const QString mdi_rocket;
    static const QString mdi_roller_skate;
    static const QString mdi_rollerblade;
    static const QString mdi_rollupjs;
    static const QString mdi_room_service;
    static const QString mdi_room_service_outline;
    static const QString mdi_rotate_3d;
    static const QString mdi_rotate_left;
    static const QString mdi_rotate_left_variant;
    static const QString mdi_rotate_orbit;
    static const QString mdi_rotate_right;
    static const QString mdi_rotate_right_variant;
    static const QString mdi_rounded_corner;
    static const QString mdi_router_wireless;
    static const QString mdi_router_wireless_settings;
    static const QString mdi_routes;
    static const QString mdi_rowing;
    static const QString mdi_rss;
    static const QString mdi_rss_box;
    static const QString mdi_ruby;
    static const QString mdi_rugby;
    static const QString mdi_ruler;
    static const QString mdi_ruler_square;
    static const QString mdi_run;
    static const QString mdi_run_fast;
    static const QString mdi_sack;
    static const QString mdi_sack_percent;
    static const QString mdi_safe;
    static const QString mdi_safety_goggles;
    static const QString mdi_sale;
    static const QString mdi_salesforce;
    static const QString mdi_sass;
    static const QString mdi_satellite;
    static const QString mdi_satellite_uplink;
    static const QString mdi_satellite_variant;
    static const QString mdi_sausage;
    static const QString mdi_saxophone;
    static const QString mdi_scale;
    static const QString mdi_scale_balance;
    static const QString mdi_scale_bathroom;
    static const QString mdi_scanner;
    static const QString mdi_scanner_off;
    static const QString mdi_school;
    static const QString mdi_scissors_cutting;
    static const QString mdi_screen_rotation;
    static const QString mdi_screen_rotation_lock;
    static const QString mdi_screw_flat_top;
    static const QString mdi_screw_lag;
    static const QString mdi_screw_machine_flat_top;
    static const QString mdi_screw_machine_round_top;
    static const QString mdi_screw_round_top;
    static const QString mdi_screwdriver;
    static const QString mdi_script;
    static const QString mdi_script_outline;
    static const QString mdi_script_text;
    static const QString mdi_script_text_outline;
    static const QString mdi_sd;
    static const QString mdi_seal;
    static const QString mdi_search_web;
    static const QString mdi_seat;
    static const QString mdi_seat_flat;
    static const QString mdi_seat_flat_angled;
    static const QString mdi_seat_individual_suite;
    static const QString mdi_seat_legroom_extra;
    static const QString mdi_seat_legroom_normal;
    static const QString mdi_seat_legroom_reduced;
    static const QString mdi_seat_outline;
    static const QString mdi_seat_recline_extra;
    static const QString mdi_seat_recline_normal;
    static const QString mdi_seatbelt;
    static const QString mdi_security;
    static const QString mdi_security_network;
    static const QString mdi_select;
    static const QString mdi_select_all;
    static const QString mdi_select_color;
    static const QString mdi_select_compare;
    static const QString mdi_select_drag;
    static const QString mdi_select_inverse;
    static const QString mdi_select_off;
    static const QString mdi_selection;
    static const QString mdi_selection_drag;
    static const QString mdi_selection_ellipse;
    static const QString mdi_selection_off;
    static const QString mdi_send;
    static const QString mdi_send_circle;
    static const QString mdi_send_circle_outline;
    static const QString mdi_send_lock;
    static const QString mdi_serial_port;
    static const QString mdi_server;
    static const QString mdi_server_minus;
    static const QString mdi_server_network;
    static const QString mdi_server_network_off;
    static const QString mdi_server_off;
    static const QString mdi_server_plus;
    static const QString mdi_server_remove;
    static const QString mdi_server_security;
    static const QString mdi_set_all;
    static const QString mdi_set_center;
    static const QString mdi_set_center_right;
    static const QString mdi_set_left;
    static const QString mdi_set_left_center;
    static const QString mdi_set_left_right;
    static const QString mdi_set_none;
    static const QString mdi_set_right;
    static const QString mdi_set_top_box;
    static const QString mdi_settings;
    static const QString mdi_settings_box;
    static const QString mdi_settings_helper;
    static const QString mdi_settings_outline;
    static const QString mdi_shape;
    static const QString mdi_shape_circle_plus;
    static const QString mdi_shape_outline;
    static const QString mdi_shape_plus;
    static const QString mdi_shape_polygon_plus;
    static const QString mdi_shape_rectangle_plus;
    static const QString mdi_shape_square_plus;
    static const QString mdi_share;
    static const QString mdi_share_outline;
    static const QString mdi_share_variant;
    static const QString mdi_sheep;
    static const QString mdi_shield;
    static const QString mdi_shield_account;
    static const QString mdi_shield_account_outline;
    static const QString mdi_shield_airplane;
    static const QString mdi_shield_airplane_outline;
    static const QString mdi_shield_check;
    static const QString mdi_shield_check_outline;
    static const QString mdi_shield_cross;
    static const QString mdi_shield_cross_outline;
    static const QString mdi_shield_half_full;
    static const QString mdi_shield_home;
    static const QString mdi_shield_home_outline;
    static const QString mdi_shield_key;
    static const QString mdi_shield_key_outline;
    static const QString mdi_shield_link_variant;
    static const QString mdi_shield_link_variant_outline;
    static const QString mdi_shield_lock;
    static const QString mdi_shield_lock_outline;
    static const QString mdi_shield_off;
    static const QString mdi_shield_off_outline;
    static const QString mdi_shield_outline;
    static const QString mdi_shield_plus;
    static const QString mdi_shield_plus_outline;
    static const QString mdi_shield_remove;
    static const QString mdi_shield_remove_outline;
    static const QString mdi_shield_search;
    static const QString mdi_ship_wheel;
    static const QString mdi_shoe_formal;
    static const QString mdi_shoe_heel;
    static const QString mdi_shoe_print;
    static const QString mdi_shopify;
    static const QString mdi_shopping;
    static const QString mdi_shopping_music;
    static const QString mdi_shovel;
    static const QString mdi_shovel_off;
    static const QString mdi_shower;
    static const QString mdi_shower_head;
    static const QString mdi_shredder;
    static const QString mdi_shuffle;
    static const QString mdi_shuffle_disabled;
    static const QString mdi_shuffle_variant;
    static const QString mdi_sigma;
    static const QString mdi_sigma_lower;
    static const QString mdi_sign_caution;
    static const QString mdi_sign_direction;
    static const QString mdi_sign_text;
    static const QString mdi_signal;
    static const QString mdi_signal_2g;
    static const QString mdi_signal_3g;
    static const QString mdi_signal_4g;
    static const QString mdi_signal_5g;
    static const QString mdi_signal_cellular_1;
    static const QString mdi_signal_cellular_2;
    static const QString mdi_signal_cellular_3;
    static const QString mdi_signal_cellular_outline;
    static const QString mdi_signal_hspa;
    static const QString mdi_signal_hspa_plus;
    static const QString mdi_signal_off;
    static const QString mdi_signal_variant;
    static const QString mdi_signature;
    static const QString mdi_signature_freehand;
    static const QString mdi_signature_image;
    static const QString mdi_signature_text;
    static const QString mdi_silo;
    static const QString mdi_silverware;
    static const QString mdi_silverware_fork;
    static const QString mdi_silverware_fork_knife;
    static const QString mdi_silverware_spoon;
    static const QString mdi_silverware_variant;
    static const QString mdi_sim;
    static const QString mdi_sim_alert;
    static const QString mdi_sim_off;
    static const QString mdi_sina_weibo;
    static const QString mdi_sitemap;
    static const QString mdi_skate;
    static const QString mdi_skew_less;
    static const QString mdi_skew_more;
    static const QString mdi_skip_backward;
    static const QString mdi_skip_forward;
    static const QString mdi_skip_next;
    static const QString mdi_skip_next_circle;
    static const QString mdi_skip_next_circle_outline;
    static const QString mdi_skip_previous;
    static const QString mdi_skip_previous_circle;
    static const QString mdi_skip_previous_circle_outline;
    static const QString mdi_skull;
    static const QString mdi_skull_crossbones;
    static const QString mdi_skull_crossbones_outline;
    static const QString mdi_skull_outline;
    static const QString mdi_skype;
    static const QString mdi_skype_business;
    static const QString mdi_slack;
    static const QString mdi_slackware;
    static const QString mdi_sleep;
    static const QString mdi_sleep_off;
    static const QString mdi_slope_downhill;
    static const QString mdi_slope_uphill;
    static const QString mdi_smog;
    static const QString mdi_smoke_detector;
    static const QString mdi_smoking;
    static const QString mdi_smoking_off;
    static const QString mdi_snapchat;
    static const QString mdi_snowflake;
    static const QString mdi_snowman;
    static const QString mdi_soccer;
    static const QString mdi_soccer_field;
    static const QString mdi_sofa;
    static const QString mdi_solar_panel;
    static const QString mdi_solar_panel_large;
    static const QString mdi_solar_power;
    static const QString mdi_solid;
    static const QString mdi_sort;
    static const QString mdi_sort_alphabetical;
    static const QString mdi_sort_ascending;
    static const QString mdi_sort_descending;
    static const QString mdi_sort_numeric;
    static const QString mdi_sort_variant;
    static const QString mdi_sort_variant_lock;
    static const QString mdi_sort_variant_lock_open;
    static const QString mdi_soundcloud;
    static const QString mdi_source_branch;
    static const QString mdi_source_commit;
    static const QString mdi_source_commit_end;
    static const QString mdi_source_commit_end_local;
    static const QString mdi_source_commit_local;
    static const QString mdi_source_commit_next_local;
    static const QString mdi_source_commit_start;
    static const QString mdi_source_commit_start_next_local;
    static const QString mdi_source_fork;
    static const QString mdi_source_merge;
    static const QString mdi_source_pull;
    static const QString mdi_source_repository;
    static const QString mdi_source_repository_multiple;
    static const QString mdi_soy_sauce;
    static const QString mdi_spa;
    static const QString mdi_spa_outline;
    static const QString mdi_space_invaders;
    static const QString mdi_speaker;
    static const QString mdi_speaker_bluetooth;
    static const QString mdi_speaker_multiple;
    static const QString mdi_speaker_off;
    static const QString mdi_speaker_wireless;
    static const QString mdi_speedometer;
    static const QString mdi_spellcheck;
    static const QString mdi_spider_web;
    static const QString mdi_spotify;
    static const QString mdi_spotlight;
    static const QString mdi_spotlight_beam;
    static const QString mdi_spray;
    static const QString mdi_spray_bottle;
    static const QString mdi_square;
    static const QString mdi_square_edit_outline;
    static const QString mdi_square_inc;
    static const QString mdi_square_inc_cash;
    static const QString mdi_square_medium;
    static const QString mdi_square_medium_outline;
    static const QString mdi_square_outline;
    static const QString mdi_square_root;
    static const QString mdi_square_root_box;
    static const QString mdi_square_small;
    static const QString mdi_squeegee;
    static const QString mdi_ssh;
    static const QString mdi_stack_exchange;
    static const QString mdi_stack_overflow;
    static const QString mdi_stadium;
    static const QString mdi_stairs;
    static const QString mdi_stamper;
    static const QString mdi_standard_definition;
    static const QString mdi_star;
    static const QString mdi_star_box;
    static const QString mdi_star_box_outline;
    static const QString mdi_star_circle;
    static const QString mdi_star_circle_outline;
    static const QString mdi_star_face;
    static const QString mdi_star_four_points;
    static const QString mdi_star_four_points_outline;
    static const QString mdi_star_half;
    static const QString mdi_star_off;
    static const QString mdi_star_outline;
    static const QString mdi_star_three_points;
    static const QString mdi_star_three_points_outline;
    static const QString mdi_steam;
    static const QString mdi_steam_box;
    static const QString mdi_steering;
    static const QString mdi_steering_off;
    static const QString mdi_step_backward;
    static const QString mdi_step_backward_2;
    static const QString mdi_step_forward;
    static const QString mdi_step_forward_2;
    static const QString mdi_stethoscope;
    static const QString mdi_sticker;
    static const QString mdi_sticker_emoji;
    static const QString mdi_stocking;
    static const QString mdi_stop;
    static const QString mdi_stop_circle;
    static const QString mdi_stop_circle_outline;
    static const QString mdi_store;
    static const QString mdi_store_24_hour;
    static const QString mdi_stove;
    static const QString mdi_strava;
    static const QString mdi_subdirectory_arrow_left;
    static const QString mdi_subdirectory_arrow_right;
    static const QString mdi_subtitles;
    static const QString mdi_subtitles_outline;
    static const QString mdi_subway;
    static const QString mdi_subway_alert_variant;
    static const QString mdi_subway_variant;
    static const QString mdi_summit;
    static const QString mdi_sunglasses;
    static const QString mdi_surround_sound;
    static const QString mdi_surround_sound_2_0;
    static const QString mdi_surround_sound_3_1;
    static const QString mdi_surround_sound_5_1;
    static const QString mdi_surround_sound_7_1;
    static const QString mdi_svg;
    static const QString mdi_swap_horizontal;
    static const QString mdi_swap_horizontal_bold;
    static const QString mdi_swap_horizontal_variant;
    static const QString mdi_swap_vertical;
    static const QString mdi_swap_vertical_bold;
    static const QString mdi_swap_vertical_variant;
    static const QString mdi_swim;
    static const QString mdi_switch;
    static const QString mdi_sword;
    static const QString mdi_sword_cross;
    static const QString mdi_symfony;
    static const QString mdi_sync;
    static const QString mdi_sync_alert;
    static const QString mdi_sync_off;
    static const QString mdi_tab;
    static const QString mdi_tab_minus;
    static const QString mdi_tab_plus;
    static const QString mdi_tab_remove;
    static const QString mdi_tab_unselected;
    static const QString mdi_table;
    static const QString mdi_table_border;
    static const QString mdi_table_column;
    static const QString mdi_table_column_plus_after;
    static const QString mdi_table_column_plus_before;
    static const QString mdi_table_column_remove;
    static const QString mdi_table_column_width;
    static const QString mdi_table_edit;
    static const QString mdi_table_large;
    static const QString mdi_table_merge_cells;
    static const QString mdi_table_of_contents;
    static const QString mdi_table_plus;
    static const QString mdi_table_remove;
    static const QString mdi_table_row;
    static const QString mdi_table_row_height;
    static const QString mdi_table_row_plus_after;
    static const QString mdi_table_row_plus_before;
    static const QString mdi_table_row_remove;
    static const QString mdi_table_search;
    static const QString mdi_table_settings;
    static const QString mdi_tablet;
    static const QString mdi_tablet_android;
    static const QString mdi_tablet_cellphone;
    static const QString mdi_tablet_ipad;
    static const QString mdi_taco;
    static const QString mdi_tag;
    static const QString mdi_tag_faces;
    static const QString mdi_tag_heart;
    static const QString mdi_tag_heart_outline;
    static const QString mdi_tag_minus;
    static const QString mdi_tag_multiple;
    static const QString mdi_tag_outline;
    static const QString mdi_tag_plus;
    static const QString mdi_tag_remove;
    static const QString mdi_tag_text_outline;
    static const QString mdi_tank;
    static const QString mdi_tape_measure;
    static const QString mdi_target;
    static const QString mdi_target_account;
    static const QString mdi_target_variant;
    static const QString mdi_taxi;
    static const QString mdi_tea;
    static const QString mdi_tea_outline;
    static const QString mdi_teach;
    static const QString mdi_teamviewer;
    static const QString mdi_telegram;
    static const QString mdi_telescope;
    static const QString mdi_television;
    static const QString mdi_television_box;
    static const QString mdi_television_classic;
    static const QString mdi_television_classic_off;
    static const QString mdi_television_guide;
    static const QString mdi_television_off;
    static const QString mdi_temperature_celsius;
    static const QString mdi_temperature_fahrenheit;
    static const QString mdi_temperature_kelvin;
    static const QString mdi_tennis;
    static const QString mdi_tennis_ball;
    static const QString mdi_tent;
    static const QString mdi_terrain;
    static const QString mdi_test_tube;
    static const QString mdi_test_tube_empty;
    static const QString mdi_test_tube_off;
    static const QString mdi_text;
    static const QString mdi_text_shadow;
    static const QString mdi_text_short;
    static const QString mdi_text_subject;
    static const QString mdi_text_to_speech;
    static const QString mdi_text_to_speech_off;
    static const QString mdi_textbox;
    static const QString mdi_textbox_password;
    static const QString mdi_texture;
    static const QString mdi_theater;
    static const QString mdi_theme_light_dark;
    static const QString mdi_thermometer;
    static const QString mdi_thermometer_alert;
    static const QString mdi_thermometer_chevron_down;
    static const QString mdi_thermometer_chevron_up;
    static const QString mdi_thermometer_lines;
    static const QString mdi_thermometer_minus;
    static const QString mdi_thermometer_plus;
    static const QString mdi_thermostat;
    static const QString mdi_thermostat_box;
    static const QString mdi_thought_bubble;
    static const QString mdi_thought_bubble_outline;
    static const QString mdi_thumb_down;
    static const QString mdi_thumb_down_outline;
    static const QString mdi_thumb_up;
    static const QString mdi_thumb_up_outline;
    static const QString mdi_thumbs_up_down;
    static const QString mdi_ticket;
    static const QString mdi_ticket_account;
    static const QString mdi_ticket_confirmation;
    static const QString mdi_ticket_outline;
    static const QString mdi_ticket_percent;
    static const QString mdi_tie;
    static const QString mdi_tilde;
    static const QString mdi_timelapse;
    static const QString mdi_timeline;
    static const QString mdi_timeline_outline;
    static const QString mdi_timeline_text;
    static const QString mdi_timeline_text_outline;
    static const QString mdi_timer;
    static const QString mdi_timer_10;
    static const QString mdi_timer_3;
    static const QString mdi_timer_off;
    static const QString mdi_timer_sand;
    static const QString mdi_timer_sand_empty;
    static const QString mdi_timer_sand_full;
    static const QString mdi_timetable;
    static const QString mdi_toaster_oven;
    static const QString mdi_toggle_switch;
    static const QString mdi_toggle_switch_off;
    static const QString mdi_toggle_switch_off_outline;
    static const QString mdi_toggle_switch_outline;
    static const QString mdi_toilet;
    static const QString mdi_toolbox;
    static const QString mdi_toolbox_outline;
    static const QString mdi_tooltip;
    static const QString mdi_tooltip_account;
    static const QString mdi_tooltip_edit;
    static const QString mdi_tooltip_image;
    static const QString mdi_tooltip_image_outline;
    static const QString mdi_tooltip_outline;
    static const QString mdi_tooltip_plus;
    static const QString mdi_tooltip_plus_outline;
    static const QString mdi_tooltip_text;
    static const QString mdi_tooltip_text_outline;
    static const QString mdi_tooth;
    static const QString mdi_tooth_outline;
    static const QString mdi_tor;
    static const QString mdi_tortoise;
    static const QString mdi_tournament;
    static const QString mdi_tower_beach;
    static const QString mdi_tower_fire;
    static const QString mdi_towing;
    static const QString mdi_track_light;
    static const QString mdi_trackpad;
    static const QString mdi_trackpad_lock;
    static const QString mdi_tractor;
    static const QString mdi_trademark;
    static const QString mdi_traffic_light;
    static const QString mdi_train;
    static const QString mdi_train_car;
    static const QString mdi_train_variant;
    static const QString mdi_tram;
    static const QString mdi_transcribe;
    static const QString mdi_transcribe_close;
    static const QString mdi_transfer_down;
    static const QString mdi_transfer_left;
    static const QString mdi_transfer_right;
    static const QString mdi_transfer_up;
    static const QString mdi_transit_connection;
    static const QString mdi_transit_connection_variant;
    static const QString mdi_transit_transfer;
    static const QString mdi_transition;
    static const QString mdi_transition_masked;
    static const QString mdi_translate;
    static const QString mdi_translate_off;
    static const QString mdi_transmission_tower;
    static const QString mdi_trash_can;
    static const QString mdi_trash_can_outline;
    static const QString mdi_treasure_chest;
    static const QString mdi_tree;
    static const QString mdi_trello;
    static const QString mdi_trending_down;
    static const QString mdi_trending_neutral;
    static const QString mdi_trending_up;
    static const QString mdi_triangle;
    static const QString mdi_triangle_outline;
    static const QString mdi_triforce;
    static const QString mdi_trophy;
    static const QString mdi_trophy_award;
    static const QString mdi_trophy_broken;
    static const QString mdi_trophy_outline;
    static const QString mdi_trophy_variant;
    static const QString mdi_trophy_variant_outline;
    static const QString mdi_truck;
    static const QString mdi_truck_check;
    static const QString mdi_truck_delivery;
    static const QString mdi_truck_fast;
    static const QString mdi_truck_trailer;
    static const QString mdi_tshirt_crew;
    static const QString mdi_tshirt_crew_outline;
    static const QString mdi_tshirt_v;
    static const QString mdi_tshirt_v_outline;
    static const QString mdi_tumble_dryer;
    static const QString mdi_tumblr;
    static const QString mdi_tumblr_box;
    static const QString mdi_tumblr_reblog;
    static const QString mdi_tune;
    static const QString mdi_tune_vertical;
    static const QString mdi_turnstile;
    static const QString mdi_turnstile_outline;
    static const QString mdi_turtle;
    static const QString mdi_twitch;
    static const QString mdi_twitter;
    static const QString mdi_twitter_box;
    static const QString mdi_twitter_circle;
    static const QString mdi_twitter_retweet;
    static const QString mdi_two_factor_authentication;
    static const QString mdi_uber;
    static const QString mdi_ubisoft;
    static const QString mdi_ubuntu;
    static const QString mdi_ultra_high_definition;
    static const QString mdi_umbraco;
    static const QString mdi_umbrella;
    static const QString mdi_umbrella_closed;
    static const QString mdi_umbrella_outline;
    static const QString mdi_undo;
    static const QString mdi_undo_variant;
    static const QString mdi_unfold_less_horizontal;
    static const QString mdi_unfold_less_vertical;
    static const QString mdi_unfold_more_horizontal;
    static const QString mdi_unfold_more_vertical;
    static const QString mdi_ungroup;
    static const QString mdi_unity;
    static const QString mdi_unreal;
    static const QString mdi_untappd;
    static const QString mdi_update;
    static const QString mdi_upload;
    static const QString mdi_upload_multiple;
    static const QString mdi_upload_network;
    static const QString mdi_upload_network_outline;
    static const QString mdi_upload_outline;
    static const QString mdi_usb;
    static const QString mdi_van_passenger;
    static const QString mdi_van_utility;
    static const QString mdi_vanish;
    static const QString mdi_variable;
    static const QString mdi_vector_arrange_above;
    static const QString mdi_vector_arrange_below;
    static const QString mdi_vector_bezier;
    static const QString mdi_vector_circle;
    static const QString mdi_vector_circle_variant;
    static const QString mdi_vector_combine;
    static const QString mdi_vector_curve;
    static const QString mdi_vector_difference;
    static const QString mdi_vector_difference_ab;
    static const QString mdi_vector_difference_ba;
    static const QString mdi_vector_ellipse;
    static const QString mdi_vector_intersection;
    static const QString mdi_vector_line;
    static const QString mdi_vector_point;
    static const QString mdi_vector_polygon;
    static const QString mdi_vector_polyline;
    static const QString mdi_vector_radius;
    static const QString mdi_vector_rectangle;
    static const QString mdi_vector_selection;
    static const QString mdi_vector_square;
    static const QString mdi_vector_triangle;
    static const QString mdi_vector_union;
    static const QString mdi_venmo;
    static const QString mdi_vhs;
    static const QString mdi_vibrate;
    static const QString mdi_vibrate_off;
    static const QString mdi_video;
    static const QString mdi_video_3d;
    static const QString mdi_video_4k_box;
    static const QString mdi_video_account;
    static const QString mdi_video_image;
    static const QString mdi_video_input_antenna;
    static const QString mdi_video_input_component;
    static const QString mdi_video_input_hdmi;
    static const QString mdi_video_input_svideo;
    static const QString mdi_video_minus;
    static const QString mdi_video_off;
    static const QString mdi_video_off_outline;
    static const QString mdi_video_outline;
    static const QString mdi_video_plus;
    static const QString mdi_video_stabilization;
    static const QString mdi_video_switch;
    static const QString mdi_video_vintage;
    static const QString mdi_view_agenda;
    static const QString mdi_view_array;
    static const QString mdi_view_carousel;
    static const QString mdi_view_column;
    static const QString mdi_view_dashboard;
    static const QString mdi_view_dashboard_outline;
    static const QString mdi_view_dashboard_variant;
    static const QString mdi_view_day;
    static const QString mdi_view_grid;
    static const QString mdi_view_headline;
    static const QString mdi_view_list;
    static const QString mdi_view_module;
    static const QString mdi_view_parallel;
    static const QString mdi_view_quilt;
    static const QString mdi_view_sequential;
    static const QString mdi_view_split_horizontal;
    static const QString mdi_view_split_vertical;
    static const QString mdi_view_stream;
    static const QString mdi_view_week;
    static const QString mdi_vimeo;
    static const QString mdi_violin;
    static const QString mdi_virtual_reality;
    static const QString mdi_visual_studio;
    static const QString mdi_visual_studio_code;
    static const QString mdi_vk;
    static const QString mdi_vk_box;
    static const QString mdi_vk_circle;
    static const QString mdi_vlc;
    static const QString mdi_voice;
    static const QString mdi_voicemail;
    static const QString mdi_volleyball;
    static const QString mdi_volume_high;
    static const QString mdi_volume_low;
    static const QString mdi_volume_medium;
    static const QString mdi_volume_minus;
    static const QString mdi_volume_mute;
    static const QString mdi_volume_off;
    static const QString mdi_volume_plus;
    static const QString mdi_volume_variant_off;
    static const QString mdi_vote;
    static const QString mdi_vote_outline;
    static const QString mdi_vpn;
    static const QString mdi_vuejs;
    static const QString mdi_walk;
    static const QString mdi_wall;
    static const QString mdi_wall_sconce;
    static const QString mdi_wall_sconce_flat;
    static const QString mdi_wall_sconce_variant;
    static const QString mdi_wallet;
    static const QString mdi_wallet_giftcard;
    static const QString mdi_wallet_membership;
    static const QString mdi_wallet_outline;
    static const QString mdi_wallet_travel;
    static const QString mdi_wallpaper;
    static const QString mdi_wan;
    static const QString mdi_washing_machine;
    static const QString mdi_watch;
    static const QString mdi_watch_export;
    static const QString mdi_watch_export_variant;
    static const QString mdi_watch_import;
    static const QString mdi_watch_import_variant;
    static const QString mdi_watch_variant;
    static const QString mdi_watch_vibrate;
    static const QString mdi_watch_vibrate_off;
    static const QString mdi_water;
    static const QString mdi_water_off;
    static const QString mdi_water_outline;
    static const QString mdi_water_percent;
    static const QString mdi_water_pump;
    static const QString mdi_watermark;
    static const QString mdi_waves;
    static const QString mdi_waze;
    static const QString mdi_weather_cloudy;
    static const QString mdi_weather_fog;
    static const QString mdi_weather_hail;
    static const QString mdi_weather_hurricane;
    static const QString mdi_weather_lightning;
    static const QString mdi_weather_lightning_rainy;
    static const QString mdi_weather_night;
    static const QString mdi_weather_partlycloudy;
    static const QString mdi_weather_pouring;
    static const QString mdi_weather_rainy;
    static const QString mdi_weather_snowy;
    static const QString mdi_weather_snowy_rainy;
    static const QString mdi_weather_sunny;
    static const QString mdi_weather_sunset;
    static const QString mdi_weather_sunset_down;
    static const QString mdi_weather_sunset_up;
    static const QString mdi_weather_windy;
    static const QString mdi_weather_windy_variant;
    static const QString mdi_web;
    static const QString mdi_webcam;
    static const QString mdi_webhook;
    static const QString mdi_webpack;
    static const QString mdi_wechat;
    static const QString mdi_weight;
    static const QString mdi_weight_gram;
    static const QString mdi_weight_kilogram;
    static const QString mdi_weight_pound;
    static const QString mdi_whatsapp;
    static const QString mdi_wheelchair_accessibility;
    static const QString mdi_whistle;
    static const QString mdi_white_balance_auto;
    static const QString mdi_white_balance_incandescent;
    static const QString mdi_white_balance_iridescent;
    static const QString mdi_white_balance_sunny;
    static const QString mdi_widgets;
    static const QString mdi_wifi;
    static const QString mdi_wifi_off;
    static const QString mdi_wifi_star;
    static const QString mdi_wifi_strength_1;
    static const QString mdi_wifi_strength_1_alert;
    static const QString mdi_wifi_strength_1_lock;
    static const QString mdi_wifi_strength_2;
    static const QString mdi_wifi_strength_2_alert;
    static const QString mdi_wifi_strength_2_lock;
    static const QString mdi_wifi_strength_3;
    static const QString mdi_wifi_strength_3_alert;
    static const QString mdi_wifi_strength_3_lock;
    static const QString mdi_wifi_strength_4;
    static const QString mdi_wifi_strength_4_alert;
    static const QString mdi_wifi_strength_4_lock;
    static const QString mdi_wifi_strength_alert_outline;
    static const QString mdi_wifi_strength_lock_outline;
    static const QString mdi_wifi_strength_off;
    static const QString mdi_wifi_strength_off_outline;
    static const QString mdi_wifi_strength_outline;
    static const QString mdi_wii;
    static const QString mdi_wiiu;
    static const QString mdi_wikipedia;
    static const QString mdi_wind_turbine;
    static const QString mdi_window_close;
    static const QString mdi_window_closed;
    static const QString mdi_window_maximize;
    static const QString mdi_window_minimize;
    static const QString mdi_window_open;
    static const QString mdi_window_restore;
    static const QString mdi_windows;
    static const QString mdi_windows_classic;
    static const QString mdi_wiper;
    static const QString mdi_wiper_wash;
    static const QString mdi_wordpress;
    static const QString mdi_worker;
    static const QString mdi_wrap;
    static const QString mdi_wrap_disabled;
    static const QString mdi_wrench;
    static const QString mdi_wrench_outline;
    static const QString mdi_wunderlist;
    static const QString mdi_xamarin;
    static const QString mdi_xamarin_outline;
    static const QString mdi_xaml;
    static const QString mdi_xbox;
    static const QString mdi_xbox_controller;
    static const QString mdi_xbox_controller_battery_alert;
    static const QString mdi_xbox_controller_battery_charging;
    static const QString mdi_xbox_controller_battery_empty;
    static const QString mdi_xbox_controller_battery_full;
    static const QString mdi_xbox_controller_battery_low;
    static const QString mdi_xbox_controller_battery_medium;
    static const QString mdi_xbox_controller_battery_unknown;
    static const QString mdi_xbox_controller_off;
    static const QString mdi_xda;
    static const QString mdi_xing;
    static const QString mdi_xing_box;
    static const QString mdi_xing_circle;
    static const QString mdi_xml;
    static const QString mdi_xmpp;
    static const QString mdi_yahoo;
    static const QString mdi_yammer;
    static const QString mdi_yeast;
    static const QString mdi_yelp;
    static const QString mdi_yin_yang;
    static const QString mdi_youtube;
    static const QString mdi_youtube_creator_studio;
    static const QString mdi_youtube_gaming;
    static const QString mdi_youtube_subscription;
    static const QString mdi_youtube_tv;
    static const QString mdi_z_wave;
    static const QString mdi_zend;
    static const QString mdi_zigbee;
    static const QString mdi_zip_box;
    static const QString mdi_zip_disk;
    static const QString mdi_zodiac_aquarius;
    static const QString mdi_zodiac_aries;
    static const QString mdi_zodiac_cancer;
    static const QString mdi_zodiac_capricorn;
    static const QString mdi_zodiac_gemini;
    static const QString mdi_zodiac_leo;
    static const QString mdi_zodiac_libra;
    static const QString mdi_zodiac_pisces;
    static const QString mdi_zodiac_sagittarius;
    static const QString mdi_zodiac_scorpio;
    static const QString mdi_zodiac_taurus;
    static const QString mdi_zodiac_virgo;
    static const QString mdi_blank;
};

#endif
