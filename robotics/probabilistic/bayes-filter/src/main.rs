use core::panic;
use std::vec;

const OPEN_STATE: u8 = 1;
const CLOSED_STATE: u8 = 0;

const PUSH: u8 = 1;
const DO_NOTHING: u8 = 0;

// After a push transition, returns the probability of i given j (open or closed)
const PUSH_TRANSITION_MATRIX: [[f32; 2]; 2] = [
    [0.2, 0.0],
    [0.8, 1.0],
];

const DO_NOTHING_MATRIX: [[f32; 2]; 2] = [
    [1.0, 0.0],
    [0.0, 1.0],
];

fn get_prob_after_action(probability_state: u8, action: u8, prev_state: u8) -> f32 {
    if action == PUSH {
        PUSH_TRANSITION_MATRIX[probability_state as usize][prev_state as usize]
    } else {
        DO_NOTHING_MATRIX[probability_state as usize][prev_state as usize]
    }
}

fn get_sensor_prob(state: u8, sensor_mark: u8) -> f32 {
    if state == OPEN_STATE {
        if sensor_mark == OPEN_STATE { 0.6 } else { 0.4 }
    } else {
        if sensor_mark == CLOSED_STATE { 0.8 } else { 0.2 }
    }
}

fn calculate_new_belief(action: u8, last_bel: f32, sense: u8) -> f32 {
    let p_bel =
        get_prob_after_action(OPEN_STATE, action, OPEN_STATE) * last_bel +
        get_prob_after_action(OPEN_STATE, action, CLOSED_STATE) * (1.0 - last_bel);

    let bel_open = get_sensor_prob(OPEN_STATE, sense) * p_bel;

    let bel_close = get_sensor_prob(CLOSED_STATE, sense) * (1.0 - p_bel);

    let norm_factor = 1.0 / (bel_open + bel_close);

    bel_open * norm_factor
}
fn main() {
    // robot's belief that the door is open at measurements time
    let mut bel = vec![0.5, 0.75];
    let mut actions = vec![DO_NOTHING,PUSH];
    let mut measurements = vec![OPEN_STATE, OPEN_STATE];

    if
        let (Some(action), Some(belief), Some(measurement)) = (
            actions.last().copied(),
            bel.last().copied(),
            measurements.last().copied(),
        )
    {
        let new_state = calculate_new_belief(action, belief, measurement);
        print!("{new_state}");
    } else {
        panic!("State empty");
    }
}
