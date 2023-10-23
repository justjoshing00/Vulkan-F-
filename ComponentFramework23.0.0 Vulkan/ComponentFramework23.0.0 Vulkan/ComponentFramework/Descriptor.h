#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>

//helper functions for creatig the descriptor

VkDescriptorSetLayoutBinding CreateDescriptorBinding(uint32_t binding_, uint32_t descriptor_count_,VkDescriptorType descriptor_type_, VkShaderStageFlagBits stage_flags_)
{
    VkDescriptorSetLayoutBinding result{};
    result.binding = binding_;
    result.descriptorCount = descriptor_count_;
    result.descriptorType = descriptor_type_;
    result.pImmutableSamplers = nullptr;
    result.stageFlags = stage_flags_;
    return result;
}


    